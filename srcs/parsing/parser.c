/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/17 17:22:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*ast_new()
{
	//algo that will build the ast
	//if (is_pipe())
		//doing smthg
	//else
		//get_simple_cmd();
	//get_children();
}

t_node	*get_children(t_token_type op, t_node *left, t_node *right)
{// get the left and right children of the parent node
}

t_node	*parser(void)
{
	//get first token from tokens list
	//ast_builder();
	//return ast or parser error
}
