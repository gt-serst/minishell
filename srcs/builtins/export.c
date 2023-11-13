/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:07:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/13 15:48:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	declare_envlst(void)
{
	t_env	*list;
	size_t	i;

	list = g_minishell.envlst;
	while (list)
	{
		if (list->value != NULL && (ft_strcmp(list->key, "_") != 0))
		{
			printf("declare -x %s=\"", list->key);
			i = 0;
			while ((list->value)[i])
			{
				if ((list->value)[i] == '$' || (list->value)[i] == '"')
					printf("\\%c", (list->value)[i++]);
				else
					printf("%c", (list->value)[i++]);
			}
			printf("\"\n");
		}
		else if (list->value == NULL && (ft_strcmp(list->key, "_") != 0))
			printf("declare -x %s\n", list->key);
		list = list->next;
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

int	ft_export(char **argv)
{
	int		i;
	int		err_code;
	char	*key;

	err_code = 0;
	i = 1;
	if (!argv[1])
		return (declare_envlst(), 0);
	while (argv[i])
	{
		if (check_key(argv[i]) == 0)
			err_code = export_err_message(argv[i]);
		else
		{
			key = env_value(argv[i]);
			if (env_exists(key))
				update_envlst(key, env_value(argv[i]), false);
			else
				update_envlst(key, env_value(argv[i]), true);
		}
		i++;
	}
	return (err_code);
}
