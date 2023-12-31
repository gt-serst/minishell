/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:52 by mde-plae          #+#    #+#             */
/*   Updated: 2023/12/28 19:27:27 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	char	*check_access(char *cmd_path)
{
	if (access(cmd_path, 0) == 0)
		return (cmd_path);
	return (NULL);
}

static char	*env_path_parsed(char *path, char *cmd, t_minishell *m)
{
	size_t	i;
	char	*cmd_path;
	char	**split_path;

	split_path = ft_split(path, ':');
	i = 0;
	while (split_path[i])
	{
		cmd_path = garbage_collector(ft_strjoin_char(
					ft_strdup(split_path[i]), ft_strdup(cmd), '/'), false);
		if (check_access(cmd_path))
			return (ft_free_malloc(split_path), cmd_path);
		i++;
	}
	ft_free_malloc(split_path);
	return (error(E_CMD_NOT_FOUND, NULL, cmd, m), NULL);
}
//if path not already in the command

char	*path_to_cmd(t_env *envlst, char *cmd, t_minishell *m)
{
	char	*value;

	if (*cmd == '\0')
		return (error(E_CMD_NOT_FOUND, NULL, cmd, m), NULL);
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (check_access(cmd), cmd);
	value = envlst_value(&envlst, "PATH");
	if (value)
		return (env_path_parsed(value, cmd, m));
	return (error(E_PATH_NOT_FOUND, NULL, cmd, m), NULL);
}
//if path already in the command
