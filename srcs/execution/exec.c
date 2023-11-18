/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:55 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/18 19:54:00 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_node(t_node *node, bool piped)
{
	if (node->type == N_CMD)
	{
		//ft_print_expanded_ast(node);
		return (exec_simple_cmd(node, piped));
	}
	else
		return (exec_pipeline(node));
}

int	exec_ast(t_node *node)
{
	if (!node)
		return (EXIT_FAILURE);
	if (recursive_expander(node) == true)
	{
		if (recursive_redir(node) == true)
		{
			return (exec_node(node, false));
		}
	}
	return (EXIT_FAILURE);
}
