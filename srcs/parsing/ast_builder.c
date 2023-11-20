/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:50:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/20 22:31:12 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_node	*get_children(t_token_type op, t_node *left, t_node *right)
{// get the left and right children of the parent node
	t_node	*pipe;

	if (g_minishell.parsing_err.type)
		return (NULL);
	pipe = new_nd(get_nd_type(op));
	if (!pipe)
		return (set_parsing_err(PE_MEM), NULL);
	//printf("Pipe\n");
	//printf("Elem left %d\n", left->type);
	//printf("Elem right %d\n", right->type);
	pipe->data.pipe.left = left;
	pipe->data.pipe.right = right;
	return (pipe);
}

t_node	*ast_builder(t_io_node **io_node)
{//give the priority for each elements in the ast according to a precedence climbing algorithm
	t_node			*left;
	t_node			*right;
	t_token_type	op;

	if (g_minishell.parsing_err.type || !g_minishell.curr_token)
		return (NULL);
	left = get_simple_cmd(io_node); //gets the left atom
	if (!left)
		return (NULL);
	while (is_pipe())
	{
		//printf("Curr Token %s\n", g_minishell.curr_token->value);
		op = g_minishell.curr_token->type;
		get_next_token();
		right = ast_builder(io_node); //get the right atom
		if (!right)
			return (left);
		left = get_children(op, left, right);
		if (!left)
			return (ast_cleaner(&left), ast_cleaner(&right), NULL);
	}
	return (left);
}
