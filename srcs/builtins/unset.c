/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:37:51 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/24 10:52:46 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	env_exists(t_env **envlst, char *key)
{
	t_env	*lst;

	lst = *envlst;
	while (lst)
	{
		if (!ft_strcmp(key, lst->key))
			return (true);
		lst = lst->next;
	}
	return (false);
}

static void	unset_env(t_env **envlst, char *key)
{
	t_env	*current;
	t_env	*prev;

	prev = NULL;
	current = *envlst;
	while (current)
	{
		if (!ft_strcmp(key, current->key))
		{
			if (prev)
				prev->next = current->next;
			else
				current = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	ft_unset(t_env **envlst, char **args)
{
	int		i;
	bool	err;

	i = 1;
	if (!args[1])
		return (0);
	err = false;
	while (args[i])
	{
		if (!env_key(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			err = true;
		}
		else
			unset_env(envlst, envlst_handler(env_key(args[i]), false));
		i++;
	}
	return (err);
}
