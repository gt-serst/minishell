/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_buitins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:37:12 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/08 15:07:43 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	exec_builtin(t_node *node) 
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args[1]));
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_env());
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(args[0], "export") == 0)
		return (ft_export(args));
	if (ft_strcmp(args[0], "unset") == 0)
		return (ft_unset(args));
	ft_exit(args);
	return (ENO_GENERAL);
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
