/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 15:40:18 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*parser(t_minishell *m)
{
	t_token	**token;

	token = &m->token;
	m->ast = ast_builder(token, m);
	if (*token)
	{
		error(E_UNEXP_TOK, (*token)->value, NULL, m);
		tkclear(token);
		return (shell_cleaner(m), NULL);
	}
	return (m->ast);
}
// core routine for parsing
//t_io_node	**io_node;

//io_node = malloc(sizeof(t_io_node*));
//if (!io_node)
	//return (NULL);
//io_node = NULL;
