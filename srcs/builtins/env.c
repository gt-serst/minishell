/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:24:26 by mde-plae          #+#    #+#             */
/*   Updated: 2024/04/29 15:18:18 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*envlst_value(t_env **envlst, char *key)
{
	t_env	*lst;

	lst = *envlst;
	while (lst)
	{
		if (!ft_strcmp(key, lst->key))
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}

char	*get_env_key(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '=')
			i++;
		else
			return (garbage_collector(ft_substr(str, 0, i), false));
	}
	return (ft_strdup(str));
}

char	*get_env_value(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (garbage_collector
				(ft_substr(str, i, ft_strlen(str) - i), false));
		}
		i++;
	}
	return (NULL);
}

void	envlst_init(t_env **envlst, char **env)
{
	char	*key;
	char	*value;
	int		i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		key = get_env_key(env[i]);
		value = get_env_value(env[i]);
		update_envlst(envlst, key, value, true);
		i++;
	}
}

int	ft_env(t_env **envlst)
{
	t_env	*lst;

	lst = *envlst;
	while (lst)
	{
		if (lst->value != NULL)
			printf("%s=%s\n", lst->key, lst->value);
		lst = lst->next;
	}
	return (0);
}
