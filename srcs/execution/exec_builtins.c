/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:37:12 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/22 15:45:10 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_builtins(t_minishell *m, char **args, bool piped)
{
	int	status;

	if (ft_strcmp(args[0], "echo") == 0)
		status = ft_echo(args);
	else if (ft_strcmp(args[0], "cd") == 0)
		status = ft_cd(m->envlst, args[1]);
	else if (ft_strcmp(args[0], "env") == 0)
		status = ft_env(m->envlst);
	else if (ft_strcmp(args[0], "pwd") == 0)
		status = ft_pwd();
	else if (ft_strcmp(args[0], "export") == 0)
		status = ft_export(m->envlst, args);
	else if (ft_strcmp(args[0], "unset") == 0)
		status = ft_unset(m->envlst, args);
	else
	{
		ft_exit(m, args, piped);
		return (EXIT_FAILURE);
	}
	return (status);
}

bool	is_builtin(char *arg)
{
	if (!arg)
		return (false);
	if (!ft_strcmp(arg, "echo")
		|| !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "exit")
		|| !ft_strcmp(arg, "pwd")
		|| !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env"))
		return (true);
	return (false);
}
