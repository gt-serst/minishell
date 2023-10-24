/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 14:47:22 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_printlst(t_minishell *m)
{
	t_token	*head;

	head = (m->tokens);
	while (head)
	{
		printf("Value %s Type %d\n", head->value, head->type);
		head = head->next;
	}
}

void	ft_printlst_reverse(t_minishell *m)
{
	t_token	*tail;

	tail = (m->tokens);
	while (tail->next)
		tail = tail->next;
	while (tail)
	{
		printf("%s\n", tail->value);
		tail = tail->prev;
	}
}
