/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:07:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/22 15:43:50 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	declare_envlst(t_env *envlst)
{
	t_env	*lst;
	size_t	i;

	lst = envlst;
	while (lst)
	{
		if (lst->value != NULL && (ft_strcmp(lst->key, "_") != 0))
		{
			printf("declare -x %s=\"", lst->key);
			i = 0;
			while ((lst->value)[i])
			{
				if ((lst->value)[i] == '$' || (lst->value)[i] == '"')
					printf("\\%c", (lst->value)[i++]);
				else
					printf("%c", (lst->value)[i++]);
			}
			printf("\"\n");
		}
		else if (lst->value == NULL && (ft_strcmp(lst->key, "_") != 0))
			printf("declare -x %s\n", lst->key);
		lst = lst->next;
	}
}

static int	check_key(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(*str) && *str != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_export(t_env *envlst, char **argv)
{
	int		i;
	int		err_code;
	char	*key;

	err_code = 0;
	i = 1;
	if (!argv[1])
		return (declare_envlst(envlst), 0);
	while (argv[i])
	{
		if (check_key(argv[i]) == 0)
			error(E_EXPORT, NULL, argv[i]);
		else
		{
			key = env_key(argv[i]);
			if (env_exists(envlst, key))
				update_envlst(envlst, key, env_value(argv[i]), false);
			else
				update_envlst(envlst, key, env_value(argv[i]), true);
		}
		i++;
	}
	return (err_code);
}
