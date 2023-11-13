/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/13 16:38:42 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	exec_child(t_node *node)
{
	int		status;
	int		fork_pid;
	char	*path_status;

	status = 0;
	g_minishell.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		path_status = path_to_cmd((node->data.simple_cmd.expanded_args)[0]);
		if (!path_status)
			exit(status);
		if (execve(path_status, node->data.simple_cmd.expanded_args, g_minishell.environ) == -1)
			exit(1);
	}
	waitpid(fork_pid, &status, 0);
	g_minishell.signint_child = false;
	exit(status);
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

int	exec_simple_cmd(t_node *node)
{
	int status;

	if (is_builtin(node->data.simple_cmd.expanded_args[0]))
	{
		status = exec_builtins(node->data.simple_cmd.expanded_args);
		// reset_stds(piped);
		return status;
	}
	else
		return (exec_child(node));
}
