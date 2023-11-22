/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:24:26 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/22 16:54:41 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	env_exists(t_env *envlst, char *key)
{
	t_env	*lst;

	lst = envlst;
	while (lst)
	{
		if (!ft_strcmp(key, lst->key))
			return (true);
		lst = lst->next;
	}
	return (false);
}

char	*env_key(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '=')
			i++;
		else
			return (envlst_handler(ft_substr(str, 0, i), false));
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
			return (envlst_handler(ft_substr(str, i, ft_strlen(str) - i), false));
		}
		i++;
	}
	return (ft_strdup(str));
}

void	envlst_init(t_env *envlst, char **env)
{
	char	*key;
	char	*value;
	int		i;

	(void)value;
	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		key = env_key(env[i]);
		value = env_value(env[i]);
		update_envlst(envlst, key, value, true);
		i++;
	}
}

int	ft_env(t_env *envlst)
{
	t_env	*lst;

	lst = envlst;
	while (lst)
	{
		if (lst->value != NULL)
			ft_printf("%s=%s\n", lst->key, lst->value);
		lst = lst->next;
	}
	return (0);
}
