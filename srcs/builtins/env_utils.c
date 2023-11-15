/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:26:14 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/15 16:39:13 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*envlst_val(char *key)
{
	t_env	*envlst;

	envlst = g_minishell.envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
}

static t_env	*new_envlst(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = envlst_handler(ft_strdup(key), false);
	if (value)
		new->value = envlst_handler(ft_strdup(value), false);
	new->next = NULL;
	return (new);
}

static void	ft_del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	*envlst_handler(void *ptr, bool clean)
{
	static t_list	*list;

	if (clean)
	{
		ft_lstclear(&list, ft_del);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&list, ft_lstnew(ptr));
		return (ptr);
	}
}

static void	envlst_back(t_env *new)
{
	t_env	*curr;

	if (!new)
		return ;
	if (!g_minishell.envlst)
	{
		g_minishell.envlst = new;
		return ;
	}
	curr = g_minishell.envlst;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = new;
}

void	update_envlst(char *key, char *value, bool create)
{
	t_env	*envlst;

	envlst = g_minishell.envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
		{
			if (value)
				envlst->value = envlst_handler(ft_strdup(value), false);
			return ;
		}
		envlst = envlst->next;
	}
	if (create)
		envlst_back(new_envlst(key, value));
}
