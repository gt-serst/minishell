/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/20 16:23:15 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	atoms are cmds and paranthesis in our case, operators are pipes
*/

t_node	*compute_operator(t_token_type op, t_node *left, t_node *right)
{// get the left and right children of the parent node
	// create a new operator node
	// to this operator node link the left and right simple cmds nodes to it
}

t_node	*compute_atom(void)
{// It handles true atoms (commands in our case), as well as parenthesized sub-expressions
	// If parenthesis then move token and launch recursive ast until the close parenthesis was found, if not error else get_next_token and return
	// Else return get_simple_cmd()
}

t_node	*recursive_ast(int min_prec)
{//give the priority for each elements in the ast according to a precedence climbing algorithm
	//atom_lhs = compute_atom() gets the left atom
	//while (is_op() && precedence >= min_prec)
	//	op = curr_token->type;
	//	get_next_token()
	//	next_min_prec = prec + 1
	//	atom_rhs = recursive_ast(next_min_prec)
	//	atom_lhs = compute_operator(op, atom_lhs, atom_rhs) performs the arithmetic computation
	//return atom_lhs
}

t_node	*parser(void)
{
	//get first token from tokens list
	//recursive_ast();
	//return ast or parser error
}
