/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:57:14 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/15 16:06:19 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exec_pipe_child(t_node *node, int *pipefd, t_ast_direction direction)
{
	int	status;

	//printf("Je suis %s\n", node->data.simple_cmd.expanded_args[0]);
	if (direction == D_LEFT)
	{
		close(pipefd[0]);
		dup2(pipefd[1], node->data.simple_cmd.fdout);
		close(pipefd[1]);
	}
	else if (direction == D_RIGHT)
	{
		close(pipefd[1]);
		dup2(pipefd[0], node->data.simple_cmd.fdin);
		close(pipefd[0]);
		//dup2(pipefd[0], 0);
	}
	status = exec_node(node);
	(shell_cleaner(), exit(status));
}

int	exec_pipeline(t_node *node)
{
	int	status;
	int	pipefd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	g_minishell.signint_child = true;
	pipe(pipefd);
	left_pid = fork();
	if (!left_pid)
		exec_pipe_child(node->data.pipe.left, pipefd, D_LEFT);
	else
	{
		right_pid = fork();
		if (!right_pid)
			exec_pipe_child(node->data.pipe.right, pipefd, D_RIGHT);
		else
		{
			(close_pipe(pipefd), waitpid(left_pid, &status, 0), waitpid(right_pid, &status, 0));
			g_minishell.signint_child = false;
			return (get_exit_status(status));
		}
	}
	return (EXIT_FAILURE);
}
