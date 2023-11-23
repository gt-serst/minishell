/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:52 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/23 14:12:18 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	char	*check_access(char *cmd_path)
{
	if (access(cmd_path, 0) == 0)
		return (cmd_path);
	return (NULL);
}

static char	*env_path_parsed(char *path, char *cmd)
{//if path not already in the command
	size_t	i;
	char	*cmd_path;
	char	**split_path;

	split_path = ft_split(path, ':');
	i = 0;
	while (split_path[i])
	{
		cmd_path = envlst_handler(ft_strjoin_char(
					ft_strdup(split_path[i]), ft_strdup(cmd), '/'), false);
		if (check_access(cmd_path))
			return (ft_free_malloc(split_path), cmd_path);
		i++;
	}
	ft_free_malloc(split_path);
	return (NULL);
}

char	*path_to_cmd(t_env *envlst, char *cmd)
{
	char	*value;

	if (*cmd == '\0')
		return (error(E_CMD_NOT_FOUND, NULL, cmd), NULL);
	if (ft_strnstr(cmd, "/", ft_strlen(cmd))) //if path already in the command
		return (check_access(cmd), cmd);
	value = envlst_val(&envlst, "PATH");
	//printf("Value %s\n", value);
	if (value)
		return (env_path_parsed(value, cmd));
	return (error(E_NO_SUCH_FILE, NULL, cmd), NULL);
}
