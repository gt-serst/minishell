/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/10 18:08:52 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	exec_child(t_node *node)
{
	int	status;
	int err_code;
	int fork_pid;
	t_path path_status;

	g_minishell.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		path_status = path_to_cmd((node->data.simple_cmd.expanded_args)[0]);
		if (path_status.err.no != ENO_SUCCESS)
		{
			err_code = set_exec_error(path_status.err);
			exit(status);
		}
		if (execve(path_status.path, node->data.simple_cmd.expanded_args, g_minishell.environ) == -1)
			exit(1);
    }
	waitpid(fork_pid, &status, 0);
	g_minishell.signint_child = false;
	return exit_status(status);
}
// Réinitialise stdin à la valeur initiale

// void	reset_stds(bool piped)
// {
// 	if (piped)
// 	{
// 		return;
// 	}
// 	dup2(g_minishell.stdin, 0);
// 	dup2(g_minishell.stdout, 1);
// }

int	exec_simple_cmd(t_node *node, bool piped)
{
	int status;

	if (is_builtin(node->data.simple_cmd.expanded_args[0]))
	{
		status = exec_builtin(node);
		// reset_stds(piped);
		return status;
	}
	else
    	return (exec_child(node));
}
