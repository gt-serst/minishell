/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:23:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 00:25:18 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	recursive_expander(t_minishell *m, t_node *node)
{
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
