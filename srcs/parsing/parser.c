/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/20 22:43:36 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*parser()
{// core routine for parsing
	t_io_node	**io_node;

	io_node = malloc(sizeof(t_io_node*));
	if (!io_node)
		return (NULL);
	io_node = NULL;
	g_minishell.curr_token = g_minishell.token;
	g_minishell.ast = ast_builder(io_node);
	if (g_minishell.curr_token)
		return (set_parsing_err(PE_SYNTAX), g_minishell.ast);
	//printf("Print left side:\n");
	//ft_print_left_side(g_minishell.ast);
	//printf("Print right side:\n");
	//ft_print_right_side(g_minishell.ast);
	//printf("Print io list:\n");
	//ft_print_io_list(&(g_minishell.ast->io_list));
	ft_print_ast(g_minishell.ast);
	return (g_minishell.ast);
}
