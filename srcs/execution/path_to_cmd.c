/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_to_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:52 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/13 16:52:58 by gt-serst         ###   ########.fr       */
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
		cmd_path = envlst_handler(ft_strjoin_char(
					ft_strdup(split_path[i]), ft_strdup(cmd), '/'));
		i++;
	}
	ft_free_malloc(split_path);
	return (cmd_path);
}

char	*path_to_cmd(char *cmd)
{
	char	*value;

	if (*cmd == '\0')
		return (set_exec_err(EXE_CMD_NOT_FOUND), NULL);
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	value = envlst_val("PATH");
	if (value)
		return (env_path_parsed(value, cmd));
	return (set_exec_err(EXE_NO_SUCH_FILE), NULL);
}
