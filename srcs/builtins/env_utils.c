/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:26:14 by mde-plae          #+#    #+#             */
/*   Updated: 2023/12/28 19:26:56 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_env	*new_envlst(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = garbage_collector(ft_strdup(key), false);
	if (value)
		new->value = garbage_collector(ft_strdup(value), false);
	new->next = NULL;
	return (new);
}

static void	ft_del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	*garbage_collector(void *ptr, bool clean)
{
	static t_list	*lst;

	if (clean)
	{
		ft_lstclear(&lst, ft_del);
		return (NULL);
	}
	else
	{
		ft_lstadd_back(&lst, ft_lstnew(ptr));
		return (ptr);
	}
}

static void	envlst_back(t_env **envlst, t_env *new)
{
	t_env	*curr;

	if (!new)
		return ;
	if (!*envlst)
	{
		*envlst = new;
		return ;
	}
	curr = *envlst;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = new;
}

void	update_envlst(t_env **envlst, char *key, char *value, bool create)
{
	t_env	*lst;

	lst = *envlst;
	while (lst)
	{
		if (!ft_strcmp(key, lst->key))
		{
			if (value)
				lst->value = garbage_collector(ft_strdup(value), false);
			return ;
		}
		lst = lst->next;
	}
	if (create)
		envlst_back(envlst, new_envlst(key, value));
}
