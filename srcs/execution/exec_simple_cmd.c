/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/10 15:53:27 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_exec_child(t_node *node)
{
	t_path path_status;
	int err_code;
	int fork_pid;

	g_minishell.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		path_status = path_to_cmd((node->expanded_args)[0]);
		if (path_status.err.no != ENO_SUCCESS)
		{
			err_code = set_exec_error(path_status.err);
			exit(status);
		}
		if (execve(path_status.path, node->expanded_args, g_minishell.environ) == -1)
			exit(1);
    }
	waitpid(fork_pid, &tmp_status, 0);
	g_minishell.signint_child = false;
	return exit_status(status);
}
// Réinitialise stdin à la valeur initiale

void	reset_stds(bool piped) 
{
	if (piped) 
	{
		return;
	}
	dup2(g_minishell.stdin, 0);
	dup2(g_minishell.stdout, 1);
}

int	exec_simple_cmd(t_node *node, bool piped) 
{
	int status;

	if (is_builtin(node->expanded_args[0])) 
	{
		status = exec_builtin(node);
		// ft_reset_stds(piped);
		return status;
	}
	else
    	return (ft_exec_child(node));
}
