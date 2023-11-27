/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:55 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 17:04:08 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_node(t_minishell *m, t_node *node, bool piped)
{
	if (node->type == N_CMD)
	{
		return (exec_simple_cmd(m, node, piped));
	}
	else
	{
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
			return (exec_node(m, node, false));
		}
	}
	return (EXIT_FAILURE);
}
