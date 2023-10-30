/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/30 13:33:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node_type get_node_type(t_token_type type)
{
	if (type == T_PIPE)
		return (N_PIPE);
	return (N_CMD);
}

t_io_type	get_io_type(t_token_type type)
{
	if (type == T_LESS)
		return (IO_IN);
	else if (type == T_GREAT)
		return (IO_OUT);
	else if (type == T_DLESS)
		return (IO_HEREDOC);
	return (IO_APPEND);
}

t_node	*new_node(t_node_type type)
{// create a new node
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	elem->type = type;
	return (elem);
}

t_io_node	*new_io_node(t_io_type type, char *value)
{
	t_io_node	*elem;

	elem = malloc(sizeof(t_io_node));
	if (!elem)
		return (NULL);
	elem->type = type;
	elem->value = value;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	addback_io_node(t_io_node **lst, t_io_node *new)
{
	t_io_node	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = &*new;
		new->prev = tmp;
	}
	else
		*lst = new;
}
