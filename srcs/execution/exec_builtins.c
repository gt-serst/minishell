/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:37:12 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/18 20:05:02 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_builtins(char **args)
{
	int	status;

	if (g_minishell.exec_err.type)
		return (0);
	else if (ft_strcmp(args[0], "echo") == 0)
		status = ft_echo(args);
	else if (ft_strcmp(args[0], "cd") == 0)
		status = ft_cd(args[1]);
	else if (ft_strcmp(args[0], "env") == 0)
		status = ft_env();
	else if (ft_strcmp(args[0], "pwd") == 0)
		status = ft_pwd();
	else if (ft_strcmp(args[0], "export") == 0)
		status = ft_export(args);
	else if (ft_strcmp(args[0], "unset") == 0)
		status = ft_unset(args);
	else
		return (EXIT_FAILURE);
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
