/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 00:41:11 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*parser(t_minishell *m)
{// core routine for parsing
	t_token	**token;
	//t_io_node	**io_node;

	//io_node = malloc(sizeof(t_io_node*));
	//if (!io_node)
		//return (NULL);
	//io_node = NULL;
	token = &m->token;
	m->ast = ast_builder(token);
	if (*token)
	{
		error(E_UNEXP_TOK, (*token)->value, NULL);
		tkclear(token);
		return (shell_cleaner(m), NULL);
	}
	//ft_print_ast(m->ast);
	return (m->ast);
}
