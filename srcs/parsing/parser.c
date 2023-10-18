/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/18 18:20:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	atoms are cmds and paranthesis in our case, operators are pipes
*/

t_node	*recursive_ast(int min_prec)
{//give the priority for each elements in the ast according to a precedence climbing algorithm
	//atom_lhs = compute_atom() gets the left atom
	//get_next_token()
	//while (is_pipe() && precedence >= min_prec)
	//	if left assoc
	//		next_min_prec = prec + 1
	//	else
	//		next_min_prec = prec
	//	get_next_token()
	//	atom_rhs = recursive_ast(next_min_prec)
	//	atom_lhs = compute_operator(op, atom_lhs, atom_rhs) performs the arithmetic computation
	//return atom_lhs
}

t_node	*compute_operator(t_token_type op, t_node *left, t_node *right)
{// get the left and right children of the parent node
	//if (is_pipe())
	//	return left | right
	//else
	//	return parse_error("unknown operator %s", op)
}

t_node	*compute_atom(void)
{// It handles true atoms (commands in our case), as well as parenthesized sub-expressions
}

t_node	*parser(void)
{
	//get first token from tokens list
	//recursive_ast();
	//return ast or parser error
}
