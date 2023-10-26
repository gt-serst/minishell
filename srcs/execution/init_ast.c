/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:09:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/10/26 15:32:32 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_leaf_init(t_node *node)
{
	if (node->args)
		node->expanded_args = ft_expand_args(node->args);
}

void	ft_ast_init(t_node *node)
{
	if (!node)
		return ;
	if(node->type == T_PIPE)
	{
		ft_ast_init(node->left)
	}
	else
		ft_leaf_init(node)
}