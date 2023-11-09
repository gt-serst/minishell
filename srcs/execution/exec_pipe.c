/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:57:14 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/09 14:11:48 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exec_pipe_child(t_node *node, int *pipefd, t_ast_direction direction)
{
	int	status;

	if (direction = D_LEFT)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	else if (direction = D_RIGHT)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
	exec_ast(node);
	ast_cleaner(node);
	exit(status);
}

void	exec_pipeline(t_node *node)
{
	int	status;
	int	pipefd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	pipe(pipefd);
	left_pid = fork();
	if (left_pid == 0)
		exec_pipe_child(node->data.pipe.left, pipefd, D_LEFT);
	else
	{
		right_pid = fork();
		if (right_pid == 0)
			exec_pipe_child(node->data.pipe.right, pipefd, D_RIGHT);
		else
		{
			close_pipe(pipefd);
			waitpid(left_pid, &status, 0);
			waitpid(right_pid, &status, 0);
		}
	}
	return (status);
}
