/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/26 11:08:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	atoms are cmds and paranthesis in our case, operators are pipes
*/

t_node	*compute_operator(t_token_type op, t_node *left, t_node *right)
{// get the left and right children of the parent node
	t_node	*new;

	new = new_node(op);
	if (!new)
		return (NULL);
	new->left = left;
	new->right = right;
	return (new);
}

t_node	*compute_atom(void)
{// It handles true atoms (commands in our case), as well as parenthesized sub-expressions
	if (g_minishell.curr_token->type == T_LPAREN)
	{
		get_next_token();
		while (g_minishell.curr_token && g_minishell.curr_token->type != T_RPAREN)
			get_next_token();
		if (g_minishell.curr_token->type == T_RPAREN)
			return (g_minishell.curr_token->type);
		else
			return (parser_err());
	}
	else
		return (get_simple_cmd());
}

t_node	*precedence_climbing(int min_prec)
{//give the priority for each elements in the ast according to a precedence climbing algorithm
	t_node			*atom_lhs;
	t_node			*atom_rhs;
	t_token_type	op;
	int				next_min_prec;

	atom_lhs = compute_atom(); //gets the left atom
	while (is_op() && curr_token_prec() >= min_prec)
	{
		op = g_minishell.curr_token->type;
		get_next_token();
		next_min_prec = min_prec + curr_token_prec();
		atom_rhs = precedence_climbing(next_min_prec);
		if (!atom_rhs)
			return (NULL);
		atom_lhs = compute_operator(op, atom_lhs, atom_rhs);
	}
	return (atom_lhs);
}

t_node	*parser()
{// core routine for parsing
	g_minishell.curr_token = g_minishell.tokens;
	g_minishell.ast = precedence_climbing(0);
	return (g_minishell.ast);
}
