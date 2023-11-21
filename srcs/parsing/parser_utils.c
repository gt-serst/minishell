/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:10:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/21 18:23:36 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*get_next_token(t_token *curr_token)
{
	if (!curr_token)
		return (NULL);
	return (curr_token->next);
}

bool	is_pipe(t_token *curr_token)
{// if is a pipe return 1 else 0
	if (!curr_token)
		return (false);
	if (curr_token->type == T_PIPE)
		return (true);
	return (false);
}

bool	is_redir(t_token_type type)
{// if is a redirection return 1 else 0
	if (type == T_INPUT || type == T_OUTPUT || type == T_HEREDOC || type == T_APPEND)
		return (true);
	return (false);
}
