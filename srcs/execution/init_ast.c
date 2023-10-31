/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:09:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/10/31 17:04:45 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_leaf_init(t_node *node)
{
	t_io_node	*io;
	
	if (node->args)
		node->expanded_args = ft_expand_args(node->args);
	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			
		}
		else
			io->expanded_value = ft_expand_args(io->value);
	}
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