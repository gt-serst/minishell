/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:23 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/31 08:59:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	io_list_cleaner(t_io_node **lst)
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

static void	cmd_node_cleaner(t_node *node)
{
	if (!node)
		return ;
	io_list_cleaner(&(node->io_list));
	free(node->args);
	if (node->expanded_args)
	{
		while ((*node->expanded_args)++)
			free(*node->expanded_args);
		free(node->expanded_args);
	}
}

static void	recursive_ast_cleaner(t_node *node)
{
	if (!node)
		return ;
	if (node->type == N_CMD)
		cmd_node_cleaner(node);
	else
	{
		if (node->left)
			recursive_ast_cleaner(node->left);
		if (node->right)
			recursive_ast_cleaner(node->right);
	}
	free(node);
}

void	ast_cleaner(t_node **ast)
{
	if (*ast)
		return ;
	recursive_ast_cleaner(*ast);
	*ast = NULL;
	tkclear(&g_minishell.tokens);
}
