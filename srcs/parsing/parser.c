/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/15 09:52:05 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*parser()
{// core routine for parsing
	g_minishell.curr_token = g_minishell.tokens;
	g_minishell.ast = ast_builder();
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
