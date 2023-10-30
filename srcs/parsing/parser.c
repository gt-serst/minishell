/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/30 15:44:27 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	atoms are cmds and paranthesis in our case, operators are pipes
*/

static t_node	*compute_op(t_token_type op, t_node *left, t_node *right)
{// get the left and right children of the parent node
	t_node	*new;

	if (g_minishell.parsing_err.type)
		return (NULL);
	new = new_nd(get_nd_type(op));
	if (!new)
		return (set_parsing_err(E_MEM), NULL);
	new->left = left;
	new->right = right;
	return (new);
}

t_node	*prec_climbing()
{//give the priority for each elements in the ast according to a precedence climbing algorithm
	t_node			*left_atom;
	t_node			*right_atom;
	t_token_type	op;

	if (g_minishell.parsing_err.type || !g_minishell.curr_token)
		return (NULL);
	left_atom = get_simple_cmd(); //gets the left atom
	if (!left_atom)
		return (NULL);
	while (is_pipe())
	{
		printf("Curr Token %s\n", g_minishell.curr_token->value);
		op = g_minishell.curr_token->type;
		get_next_token();
		right_atom = prec_climbing(); //get the right atom
		if (!right_atom)
			return (left_atom);
		left_atom = compute_op(op, left_atom, right_atom);
		if (!left_atom)
			return (clear_ast(&left_atom), clear_ast(&right_atom), NULL);
	}
	return (left_atom);
}

t_node	*parser()
{// core routine for parsing
	g_minishell.curr_token = g_minishell.tokens;
	g_minishell.ast = prec_climbing();
	if (g_minishell.curr_token)
		return (set_parsing_err(E_SYNTAX), g_minishell.ast);
	printf("Print left side:\n");
	ft_print_left_side(g_minishell.ast);
	printf("Print right side:\n");
	ft_print_right_side(g_minishell.ast);
	printf("Print io list:\n");
	ft_print_io_list(&(g_minishell.ast->io_list));
	return (g_minishell.ast);
}
