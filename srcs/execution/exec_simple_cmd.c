/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/16 15:45:51 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	close_io(void)
{
	dup2(g_minishell.in, STDIN_FILENO);
	dup2(g_minishell.out, STDOUT_FILENO);
	close(g_minishell.in);
	close(g_minishell.out);
}

static int	exec_child(t_node *node)
{
	int		status;
	int		fork_pid;
	char	*path_status;

	g_minishell.signint_child = true;
	g_minishell.in = dup(STDIN_FILENO);
	g_minishell.out = dup(STDOUT_FILENO);
	dup2(node->data.simple_cmd.fdin, STDIN_FILENO);
	dup2(node->data.simple_cmd.fdout, STDOUT_FILENO);
	fork_pid = fork();
	if (!fork_pid)
	{
		path_status = path_to_cmd((node->data.simple_cmd.expanded_args[0]));
		printf("Path status %s\n", path_status);
		if (!path_status)
		{
			set_exec_err(EXE_CMD_NOT_FOUND);
			exec_err_handler();
			(shell_cleaner(), exit(1));
		}
		//printf("\n\nn\n\n\n");
		if (execve(path_status, node->data.simple_cmd.expanded_args, g_minishell.environ) == -1)
		{
			printf("Hello\n");
			perror("error");
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
	// printf("Hello\n");
	// close(node->data.simple_cmd.fdin);
	// close(node->data.simple_cmd.fdout);
	waitpid(fork_pid, &status, 0);
	g_minishell.signint_child = false;
	close_io();
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
	// if (!node->data.simple_cmd.expanded_args)
	// {
	// 	printf("Hello\n\n\n\n\n");
	// }
	if (is_builtin(node->data.simple_cmd.expanded_args[0]))
	{
		status = exec_builtins(node->data.simple_cmd.expanded_args);
		// reset_stds(piped);
		return (status);
	}
	else
		return (exec_child(node));
}
