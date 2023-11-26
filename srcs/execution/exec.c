/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:55 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/26 23:23:50 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_node(t_minishell *m, t_node *node, bool piped)
{
	if (node->type == N_CMD)
	{
		printf("Simple cmd detected\n");
		return (exec_simple_cmd(m, node, piped));
	}
	else
	{
		printf("Pipe detected\n");
		return (exec_pipeline(m, node));
	}
}

int	exec_ast(t_minishell *m, t_node *node)
{
	if (!node)
		return (EXIT_FAILURE);
	if (recursive_expander(m, node) == true)
	{
		if (recursive_redir(m, node) == true)
		{
			ft_print_expanded_ast(node);
			return (exec_node(m, node, false));
		}
	}
	return (EXIT_FAILURE);
}
