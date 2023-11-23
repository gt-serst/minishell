/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:57:14 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 16:56:52 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exec_pipe_child(t_minishell *m, t_node *node, int *pipefd, t_ast_direction direction)
{
	int	status;

	if (direction == D_LEFT)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	else if (direction == D_RIGHT)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
	status = exec_node(m, node, true);
	(shell_cleaner(m), exit(status));
}

int	exec_pipeline(t_minishell *m, t_node *node)
{
	int	status;
	int	pipefd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	g_signint = 1;
	pipe(pipefd);
	left_pid = fork();
	if (!left_pid)
		exec_pipe_child(m, node->data.pipe.left, pipefd, D_LEFT);
	else
	{
		right_pid = fork();
		if (!right_pid)
			exec_pipe_child(m, node->data.pipe.right, pipefd, D_RIGHT);
		else
		{
			(close_pipe(pipefd), waitpid(left_pid, &status, 0), waitpid(right_pid, &status, 0));
			g_signint = 0;
			return (get_exit_status(status));
		}
	}
	return (EXIT_FAILURE);
}
