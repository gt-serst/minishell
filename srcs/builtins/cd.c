/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:59:51 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/07 16:28:01 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	new_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (1);
	return (update_envlst("PWD", cwd, false), 0);
}

static int	ft_cd(char *path)
{
	if (!path || strcmp(path, "~") == 0)
		return (cd_home_user());
	if (chdir(path) != 0)
		return (ft_cd_err_msg(path));
	update_envlst("OLDPWD", envlst_val("PWD"), false);
	return (new_pwd());
}

static int	cd_home_user(void)
{
	char	*home;

	update_envlst("OLDPWD", envlst_val("PWD"), false);
	home = envlst_val("HOME");
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) == 0)
	{
		update_envlst("PWD", home, false);
		return (0);
	}
	return (1);
}
