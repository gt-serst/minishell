/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:23 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/30 15:51:02 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	clear_io_list(t_io_node **lst)
{
	t_io_node	*current;
	t_io_node	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		if (current->expanded_value)
		{
			while ((*current->expanded_value)++)
				free(*current->expanded_value);
			free(current->expanded_value);
		}
		current = next;
		free(current);
	}
	*lst = NULL;
}

static void	clear_cmd_node(t_node *node)
{
	if (!node)
		return ;
	clear_io_list(&(node->io_list));
	free(node->args);
	if (node->expanded_args)
	{
		while ((*node->expanded_args)++)
			free(*node->expanded_args);
		free(node->expanded_args);
	}
}

static void	recursive_clear_ast(t_node *node)
{
	if (!node)
		return ;
	if (node->type == N_CMD)
		clear_cmd_node(node);
	else
	{
		if (node->left)
			recursive_clear_ast(node->left);
		if (node->right)
			recursive_clear_ast(node->right);
	}
	free(node);
}

void	clear_ast(t_node **ast)
{
	if (*ast)
		return ;
	recursive_clear_ast(*ast);
	*ast = NULL;
	tkclear(&g_minishell.tokens);
}
