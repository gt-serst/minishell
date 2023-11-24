/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:59:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 11:56:19 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*new_tk(void *content, t_token_type type)
{
	t_token	*elem;

	elem = malloc(sizeof(t_token));
	if (!elem)
		return (error(E_MEM, NULL, NULL), NULL);
	elem->value = content;
	elem->type = type;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
// create a new node and store the value of the cmd part

void	tk_lstadd_back(t_token **token, t_token *elem)
{
	t_token	*tmp;

	if (!token || !elem)
		return ;
	tmp = *token;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = &*elem;
		elem->prev = tmp;
	}
	else
		*token = elem;
}
// add the new node previously created to the linked list token

void	tkclear(t_token **token)
{
	t_token	*current;
	t_token	*next;

	if (!token)
		return ;
	current = *token;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		current = next;
		free(current);
	}
	*token = NULL;
}
