/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/15 16:10:55 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	exec_child(t_node *node)
{
	int		status;
	int		fork_pid;
	char	*path_status;

	g_minishell.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		path_status = path_to_cmd((node->data.simple_cmd.expanded_args)[0]);
		//printf("Failed");
		if (!path_status)
		{
			set_exec_err(EXE_CMD_NOT_FOUND);
			exec_err_handler();
			(shell_cleaner(), exit(1));
		}
		//printf("\n\nn\n\n\n");
		if (execve(path_status, node->data.simple_cmd.expanded_args, g_minishell.environ) == -1)
		{
			// int i = 0;
			// while(g_minishell.environ[i])
			// {
			// 	printf("%s\n", g_minishell.environ[i]);
			// 	i++;
			// }
			// while(node->data.simple_cmd.expanded_args)
			// 	printf("%s\n", *(node->data.simple_cmd.expanded_args)++);
			(shell_cleaner(), exit(1));
		}
	}
	waitpid(fork_pid, &status, 0);
	g_minishell.signint_child = false;
	return (get_exit_status(status));
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

	if (g_minishell.exec_err.type)
		return (0);
/*
	if (!node->data.simple_cmd.expanded_args)
	{
		printf("Hello\n\n\n\n\n");
	}
*/
	if (is_builtin(node->data.simple_cmd.expanded_args[0]))
	{
		status = exec_builtins(node->data.simple_cmd.expanded_args);
		// reset_stds(piped);
		return (status);
	}
	else
		return (exec_child(node));
}
