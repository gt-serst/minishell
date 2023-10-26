/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/26 15:45:05 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	atoms are cmds and paranthesis in our case, operators are pipes
*/

static t_node	*compute_op(t_token_type op, t_node *left, t_node *right)
{// get the left and right children of the parent node
	t_node	*new;

	new = new_node(get_node_type(op));
	if (!new)
		return (set_parsing_err(E_MEM), NULL);
	new->left = left;
	new->right = right;
	return (new);
}

static t_node	*compute_atom(void)
{// It handles true atoms (commands in our case), as well as parenthesized sub-expressions
	t_node	*node;

	if (g_minishell.curr_token->type == T_LPAREN)
	{
		get_next_token();
		node = precedence_climbing(0);
		if (!node)
			return (set_parsing_err(E_MEM), NULL);
		if (!g_minishell.curr_token
			|| g_minishell.curr_token->type != T_RPAREN)
			return (set_parsing_err(E_SYNTAX), node);
		get_next_token();
		return (node);
	}
	else
		return (get_simple_cmd());
}

t_node	*precedence_climbing(int min_prec)
{//give the priority for each elements in the ast according to a precedence climbing algorithm
	t_node			*left_atom;
	t_node			*right_atom;
	t_token_type	op;
	int				next_min_prec;

	left_atom = compute_atom(); //gets the left atom
	if (!left_atom)
		return (NULL);
	while (is_op() && curr_token_prec() >= min_prec)
	{
		op = g_minishell.curr_token->type;
		get_next_token();
		next_min_prec = min_prec + curr_token_prec();
		right_atom = precedence_climbing(next_min_prec); //get the right atom
		if (!right_atom)
			return (NULL);
		left_atom = compute_op(op, left_atom, right_atom);
		if (!left_atom)
			return (NULL);
	}
	return (left_atom);
}

t_node	*parser()
{// core routine for parsing
	g_minishell.curr_token = g_minishell.tokens;
	g_minishell.ast = precedence_climbing(0);
	if (g_minishell.curr_token)
		return (set_parsing_err(E_SYNTAX), g_minishell.ast);
	return (g_minishell.ast);
}
