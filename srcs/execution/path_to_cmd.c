/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:52 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/10 16:03:56 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*env_path_parsed(char *path, char *cmd)
{
	size_t	i;
	char	*cmd_path;
	char	**split_path;

	split_path = ft_split(path, ':');
	i = 0;
	while (split_path[i])
	{
		cmd_path = envlst_handler(ft_strjoin_with_f(
					ft_strdup(split_path[i]), ft_strdup(cmd), '/'));
		i++;
	}
	ft_free_array(split_path);
	return (cmd_path);
}

char	*path_to_cmd(char *cmd)
{
	char	*value;

	if (*cmd == '\0')
		return (set_exec_err());
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (set_exec_err();
	value = ft_get_envlst_val("PATH");
	if (value)
		return (env_path_parsed(value, cmd));
	return (set_exec_err());
}
