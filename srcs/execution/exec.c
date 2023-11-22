/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:55 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/22 16:13:22 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_node(t_minishell *m, t_node *node, bool piped)
{
	if (node->type == N_CMD)
		return (exec_simple_cmd(m, node, piped));
	else
		return (exec_pipeline(m, node));
}

int	exec_ast(t_minishell *m, t_node *node)
{
	if (!node)
		return (EXIT_FAILURE);
	if (recursive_expander(m, node) == true)
	{
		if (recursive_redir(node) == true)
			return (exec_node(m, node, false));
	}
	return (EXIT_FAILURE);
}
