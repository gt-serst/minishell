/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/27 15:31:40 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reset_io(t_minishell *m, bool piped)
{
	if (piped)
		return ;
	dup2(m->input, STDIN_FILENO);
	close(m->input);
	dup2(m->output, STDOUT_FILENO);
	close(m->output);
}

static void	exec_child_process(t_minishell *m, t_node *node)
{
	char	*path_status;

	path_status = path_to_cmd(m->envlst,
			node->data.simple_cmd.expanded_args[0]);
	if (!path_status)
	{
		shell_cleaner(m);
		exit(1);
	}
	if (execve(path_status, node->data.simple_cmd.expanded_args, m->env) == -1)
	{
		shell_cleaner(m);
		exit(1);
	}
}

static int	exec_child(t_minishell *m, t_node *node)
{
	int	status;
	int	fork_pid;

	g_signint = 1;
	fork_pid = fork();
	if (!fork_pid)
		exec_child_process(m, node);
	waitpid(fork_pid, &status, 0);
	g_signint = 0;
	return (get_exit_status(status));
}

static void	prepare_redirections(t_minishell *m, t_node *node)
{
	m->input = dup(STDIN_FILENO);
	m->output = dup(STDOUT_FILENO);
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

int	exec_simple_cmd(t_minishell *m, t_node *node, bool piped)
{
	int	status;

	if (!node->data.simple_cmd.expanded_args[0])
		return (EXIT_FAILURE);
	prepare_redirections(m, node);
	if (is_builtin(node->data.simple_cmd.expanded_args[0]))
	{
		status = exec_builtins(m, node->data.simple_cmd.expanded_args, piped);
		return (reset_io(m, piped), status);
	}
	else
	{
		status = exec_child(m, node);
		return (reset_io(m, piped), status);
	}
}
