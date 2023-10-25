/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/25 11:43:13 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_printlst(t_token **t)
{
	t_token	*head;

	head = (*t);
	while (head)
	{
		printf("Value %s Type %d\n", head->value, head->type);
		head = head->next;
	}
}

void	ft_printlst_reverse(t_token **t)
{
	t_token	*tail;

	tail = (*t);
	while (tail->next)
		tail = tail->next;
	while (tail)
	{
		printf("%s\n", tail->value);
		tail = tail->prev;
	}
}
