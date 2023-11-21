/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/21 18:29:53 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node_type	get_nd_type(t_token_type type)
{
	if (type == T_PIPE)
		return (N_PIPE);
	return (N_CMD);
}

t_io_node_type	get_io_nd_type(t_token_type type)
{
	if (type == T_INPUT)
		return (IO_INPUT);
	if (type == T_OUTPUT)
		return (IO_OUTPUT);
	if (type == T_HEREDOC)
		return (IO_HEREOC);
	return (IO_APPEND);
}

t_node	*new_nd(t_node_type type)
{// create a new simple command node
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	ft_bzero(elem, sizeof(t_node));
	elem->type = type;
	return (elem);
}

t_io_node	*new_io_nd(t_io_node_type type)
{// create a new io node
	t_io_node	*elem;

	elem = malloc(sizeof(t_io_node));
	if (!elem)
		return (NULL);
	ft_bzero(elem, sizeof(t_io_node));
	elem->type = type;
	return (elem);
}

void	io_lstadd_back(t_io_node **io_node, t_io_node *elem)
{// add the new node previously created to the io nodes linked list
	t_io_node	*tmp;

	if (!io_node || !elem)
		return ;
	tmp = *io_node;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = &*elem;
	}
	else
		*io_node = elem;
}
