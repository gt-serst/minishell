/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/20 17:42:15 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

void	close_io(bool piped)
{
	if (piped)
		return ;
	dup2(g_minishell.in, STDIN_FILENO);
	dup2(g_minishell.out, STDOUT_FILENO);
	close(g_minishell.in);
	close(g_minishell.out);
}

static int	exec_child(t_node *node, bool piped)
{
	int		status;
	int		fork_pid;
	char	*path_status;

	g_minishell.signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		path_status = path_to_cmd((node->data.simple_cmd.expanded_args[0]));
		//printf("Path status %s\n", path_status);
		if (!path_status)
		{
			set_exec_err(EXE_CMD_NOT_FOUND);
			exec_err_handler();
			(shell_cleaner(), exit(1));
		}
		//printf("Result:\n");
		//printf("%s\n", node->data.simple_cmd.expanded_args[0]);
		//printf("%s\n", node->data.simple_cmd.expanded_args[1]);
		//printf("Txt fd: %d\n", node->data.simple_cmd.fdin);
		if (execve(path_status, node->data.simple_cmd.expanded_args, g_minishell.environ) == -1)
		{
			//printf("%s\n", node->data.simple_cmd.expanded_args[0]);
			//error(errno, 0, node->data.simple_cmd.expanded_args[0]);
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
	//printf("Exec fin\n");
	waitpid(fork_pid, &status, 0);
	g_minishell.signint_child = false;
	//printf("Txt fd before closing: %d\n", node->data.simple_cmd.fdin);
	close(node->data.simple_cmd.fdin);
	close(node->data.simple_cmd.fdout);
	close_io(piped);
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

int	exec_simple_cmd(t_node *node, bool piped)
{
	int status;

	if (g_minishell.exec_err.type)
		return (0);
	if (!node->data.simple_cmd.expanded_args)
	{
		close_io(piped);
		return (EXIT_FAILURE);
	}
	//printf("Stdin fd %d\n", node->data.simple_cmd.fdin);
	//printf("Stdout fd %d\n", node->data.simple_cmd.fdout);
	g_minishell.in = dup(STDIN_FILENO);
	g_minishell.out = dup(STDOUT_FILENO);

	dup2(node->data.simple_cmd.fdin, STDIN_FILENO);
	//printf("Hello\n");
	dup2(node->data.simple_cmd.fdout, STDOUT_FILENO); // le contenu dans txt s'efface à cette ligne
	if (is_builtin(node->data.simple_cmd.expanded_args[0]))
	{
		status = exec_builtins(node->data.simple_cmd.expanded_args, piped);
		close_io(piped);
		return (status);
	}
	else
		return (exec_child(node, piped));
}
