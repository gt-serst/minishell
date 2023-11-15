/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:23:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/15 16:46:51 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	recursive_expander(t_node *node)
{
	// printf("EXPANDED AST:\n");
	//ft_print_expanded_ast(node);
	if (!node || g_minishell.expand_err.type)
		return (false);
	if (node->type == N_CMD)
	{
		if (!expand_args(node))
			return (false);
	}
	if (node->data.pipe.left != NULL)
	{
		if (!recursive_expander(node->data.pipe.left))
			return (false);
		if (!recursive_expander(node->data.pipe.right))
			return (false);
	}
	return (true);
}
