/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/14 09:50:43 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node_type get_nd_type(t_token_type type)
{
	if (type == T_PIPE)
		return (N_PIPE);
	return (N_CMD);
}

t_node	*new_nd(t_node_type type)
{// create a new node
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	ft_bzero(elem, sizeof(t_node));
	elem->type = type;
	return (elem);
}
