/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:59:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/14 10:09:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*new_tk(void *content, t_token_type type)
{// create a new node and store the value of the cmd part
	t_token	*elem;

	elem = malloc(sizeof(t_token));
	if (!elem)
		return (set_token_err(TE_MEM), NULL);
	elem->value = content;
	elem->type = type;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	tkadd_back(t_token **t, t_token *elem)
{// add the new node previously created to the linked list token
	t_token	*tmp;

	if (!t || !elem)
		return ;
	tmp = *t;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = &*elem;
		elem->prev = tmp;
	}
	else
		*t = elem;
}

void	tkclear(t_token **t)
{
	t_token	*current;
	t_token	*next;

	if (!t)
		return ;
	current = *t;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		current = next;
		free(current);
	}
	*t = NULL;
}
