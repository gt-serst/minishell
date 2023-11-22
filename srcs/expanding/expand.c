/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:23:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/22 16:14:08 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	recursive_expander(t_minishell *m, t_node *node)
{
	// printf("EXPANDED AST:\n");
	//ft_print_expanded_ast(node);
	if (!node)
		return (false);
	if (node->type == N_CMD)
	{
		if (!expand_args(m ,node))
			return (false);
	}
	if (node->data.pipe.left != NULL)
	{
		if (!recursive_expander(m, node->data.pipe.left))
			return (false);
		if (!recursive_expander(m, node->data.pipe.right))
			return (false);
	}
	return (true);
}
