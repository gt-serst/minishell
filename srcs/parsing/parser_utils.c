/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:10:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/25 17:18:39 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_next_token(void)
{// get the next token of the tokens list
	g_minishell.curr_token = g_minishell.curr_token->next;
}

bool	is_op(void)
{// if is a pipe return 1 else 0
	if (g_minishell.curr_token->type == T_PIPE)
		return (true);
	return (false);
}

bool	is_redir(t_token_type type)
{// if is a redirection return 1 else 0
	if (g_minishell.curr_token->type == T_LESS
		|| g_minishell.curr_token->type == T_GREAT
		|| g_minishell.curr_token->type == T_DLESS
		|| g_minishell.curr_token->type == T_DGREAT)
		return (true);
	return (false);
}
