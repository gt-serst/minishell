/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:26:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/17 17:23:07 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node_type get_node_type(t_token_type type)
{
}

t_io_type	get_io_type(t_token_type type)
{
}

t_node	node_new(t_node_type type)
{// create a new node
}

t_io_node	*new_io_node(t_token_type type, char *value)
{
}

void	append_io_node(t_io_node **lst, t_io_node *new)
{
}
