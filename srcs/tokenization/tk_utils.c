/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:59:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 15:55:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*new_tk(void *content, t_token_type type)
{// create a new node and store the value of the cmd part
	t_token	*elem;

	elem = malloc(sizeof(t_token));
	if (!elem)
		return (NULL);
	elem->value = content;
	elem->type = type;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	tkadd_back(t_token **t, t_token *new)
{// add the new node previously created to the linked list token
	t_token	*tmp;

	if (!t || !new)
		return ;
	tmp = *t;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = &*new;
		new->prev = tmp;
	}
	else
		*t = new;
}

void	tkclear(t_token **token)
{
}
