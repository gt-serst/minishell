/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:59:51 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/23 14:02:34 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	new_pwd(t_env **envlst)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (1);
	return (update_envlst(envlst, "PWD", cwd, false), 0);
}

static int	cd_home_user(t_env **envlst)
{
	char	*home;

	update_envlst(envlst, "OLDPWD", envlst_val(envlst, "PWD"), false);
	home = envlst_val(envlst, "HOME");
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) == 0)
	{
		update_envlst(envlst, "PWD", home, false);
		return (0);
	}
	return (1);
}


static int	cd_err_msg(char *err_msg)
{
	ft_putstr_fd("bash: cd: `", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("': No such file or directory\n", 2);
	return (1);
}

int	ft_cd(t_env **envlst, char *path)
{
	if (!path || ft_strcmp(path, "~") == 0)
		return (cd_home_user(envlst));
	if (chdir(path) != 0)
		return (cd_err_msg(path));
	update_envlst(envlst, "OLDPWD", envlst_val(envlst, "PWD"), false);
	return (new_pwd(envlst));
}
