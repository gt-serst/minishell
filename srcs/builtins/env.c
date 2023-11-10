/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:24:26 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/10 18:10:06 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	env_exists(char *key)
{
	t_env	*envlst;

	envlst = g_minishell.envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
			return (true);
		envlst = envlst->next;
	}
	return (false);
}

char	*env_key(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == envlst_handler(ft_substr(str, 0, i), false));
		i++;
	}
	return (ft_strdup(str));
}

char	*env_value(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (envlst_handler(
					ft_substr(str, i, ft_strlen(str) - i), false));
		}
		i++;
	}
}

void	envlst_init(void)
{
	char	**envlst;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	envlst = g_minishell.environ;
	if (!envlst)
		return ;
	while (envlst)
	{
		key = env_key(envlst[i]);
		value = env_value(envlst[i]);
		update_envlst(key, value, true);
		i++;
	}
}

int	env(void)
{
	t_env	*list;

	list = g_minishell.envlst;
	while (list)
	{
		if (list->value != NULL)
			ft_printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	return (0);
}
