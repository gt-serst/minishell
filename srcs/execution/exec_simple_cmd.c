/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/23 14:41:36 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

void	close_io(t_minishell *m, bool piped)
{
	if (piped)
		return ;
	dup2(m->input, STDIN_FILENO);
	close(m->input);
	dup2(m->output, STDOUT_FILENO);
	close(m->output);
}

static int	exec_child(t_minishell *m, t_node *node)
{
	int		status;
	int		fork_pid;
	char	*path_status;

	g_signint_child = true;
	fork_pid = fork();
	if (!fork_pid)
	{
		//printf("Expanded cmd in exec child %s\n", node->data.simple_cmd.expanded_args[0]);
		path_status = path_to_cmd(m->envlst, (node->data.simple_cmd.expanded_args[0]));
		//printf("Path %s\n", path_status);
		if (!path_status)
		{
			error(E_CMD_NOT_FOUND, NULL, node->data.simple_cmd.expanded_args[0]);
			(shell_cleaner(m), exit(1));
		}
		if (execve(path_status, node->data.simple_cmd.expanded_args, m->env) == -1)
		{
			error(E_CMD_NOT_FOUND, NULL, node->data.simple_cmd.expanded_args[0]);
			(shell_cleaner(m), exit(1));
		}
	}
	waitpid(fork_pid, &status, 0);
	g_signint_child = false;
	return (get_exit_status(status));
}

int	exec_simple_cmd(t_minishell *m, t_node *node, bool piped)
{
	int status;
	if (piped)
	{
		if (node->data.simple_cmd.fdin != 0)
		{
			dup2(node->data.simple_cmd.fdin, STDIN_FILENO);
			close(node->data.simple_cmd.fdin);
		}
		if (node->data.simple_cmd.fdout != 1)
		{
			dup2(node->data.simple_cmd.fdout, STDOUT_FILENO);
			close(node->data.simple_cmd.fdout);
		}
	}
	else
	{
		if (node->data.simple_cmd.fdin != 0)
		{
			dup2(node->data.simple_cmd.fdin, STDIN_FILENO);
			close(node->data.simple_cmd.fdin);
		}
		if (node->data.simple_cmd.fdout == 1)
		{
			dup2(node->data.simple_cmd.fdout, STDOUT_FILENO);
			close(node->data.simple_cmd.fdout);
		}
	}
	if (is_builtin(node->data.simple_cmd.expanded_args[0]))
	{
		status = exec_builtins(m, node->data.simple_cmd.expanded_args, piped);
		return (status);
	}
	else
	{
		status = exec_child(m, node);
		close_io(m, piped);
		return (status);
	}
}
