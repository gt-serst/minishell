/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:50:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/22 17:23:08 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_node	*get_children(t_token_type op, t_node *left, t_node *right)
{// get the left and right children of the parent node
	t_node	*pipe;

	pipe = new_nd(get_nd_type(op));
	if (!pipe)
		return (error(E_MEM, NULL, NULL), NULL);
	pipe->data.pipe.left = left;
	pipe->data.pipe.right = right;
	return (pipe);
}

t_node	*ast_builder(t_token **token, t_token *curr_token)
{//give the priority for each elements in the ast according to a precedence climbing algorithm
	t_node			*left;
	t_node			*right;
	t_token_type	op;

	if (!token || !curr_token)
		return (NULL);
	left = get_simple_cmd(curr_token); //gets the left atom
	if (!left)
		return (NULL);
	while (is_pipe(curr_token))
	{
		//printf("Curr Token %s\n", g_minishell.curr_token->value);
		op = curr_token->type;
		curr_token = get_next_token(curr_token);
		right = ast_builder(token, curr_token); //get the right atom
		if (!right)
			return (left);
		left = get_children(op, left, right);
		if (!left)
			return (ast_cleaner(&left, token), ast_cleaner(&right, token), NULL);
	}
	return (left);
}
