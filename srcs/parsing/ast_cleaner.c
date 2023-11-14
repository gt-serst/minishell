/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:23 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/14 09:51:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cmd_node_cleaner(t_node *node)
{
	if (!node)
		return ;
	ft_free_malloc(node->data.simple_cmd.args);
	ft_free_malloc(node->data.simple_cmd.expanded_args);
}

static void	recursive_ast_cleaner(t_node *node)
{
	if (!node)
		return ;
	if (node->type == N_CMD)
		cmd_node_cleaner(node);
	else
	{
		if (node->data.pipe.left)
			recursive_ast_cleaner(node->data.pipe.left);
		if (node->data.pipe.right)
			recursive_ast_cleaner(node->data.pipe.right);
	}
	free(node);
}

void	ast_cleaner(t_node **ast)
{
	if (!*ast)
		return ;
	recursive_ast_cleaner(*ast);
	*ast = NULL;
	tkclear(&g_minishell.tokens);
}
