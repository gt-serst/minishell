/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/21 18:31:38 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*parser(t_token **token)
{// core routine for parsing
	//t_io_node	**io_node;
	t_node	**ast;
	t_token	*curr_token;

	//io_node = malloc(sizeof(t_io_node*));
	//if (!io_node)
		//return (NULL);
	//io_node = NULL;
	curr_token = *token;
	ast = ast_builder(token, curr_token);
	if (curr_token)
		return (NULL);
	return (&ast);
}
