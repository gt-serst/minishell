/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:50:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 11:43:43 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_node	*get_children(t_token_type op, t_node *left, t_node *right)
{
	t_node	*pipe;

	pipe = new_nd(get_nd_type(op));
	if (!pipe)
		return (error(E_MEM, NULL, NULL), NULL);
	pipe->data.pipe.left = left;
	pipe->data.pipe.right = right;
	return (pipe);
}
// get the left and right children of the parent node

t_node	*ast_builder(t_token **curr_token)
{
	t_node			*left;
	t_node			*right;
	t_token_type	op;

	if (!*curr_token)
		return (NULL);
	left = get_simple_cmd(curr_token);
	if (!left)
		return (NULL);
	while (*curr_token && is_pipe(*curr_token))
	{
		op = (*curr_token)->type;
		get_next_token(curr_token);
		right = ast_builder(curr_token);
		if (!right)
			return (left);
		left = get_children(op, left, right);
		if (!left)
			return (ast_cleaner(&left), ast_cleaner(&right), NULL);
	}
	return (left);
}
//give the priority for each elements
// in the ast according to a precedence climbing algorithm
