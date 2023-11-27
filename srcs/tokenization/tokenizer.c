/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:37:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 14:11:46 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	unexpected_token(char c)
{
	if (c == ';')
		return (true);
	else if (c == '\\')
		return (true);
	return (false);
}

t_token	*tokenizer(t_minishell *m)
{
	t_token	**token;
	t_token	*new_token;
	char	*cmd_line;

	token = &m->token;
	cmd_line = m->cmd_line;
	while (ft_isspace(*cmd_line))
		cmd_line++;
	while (*(cmd_line))
	{
		if (ft_ismetachar(*cmd_line))
			new_token = separator_handler(&cmd_line, m);
		else
			new_token = identifier_handler(&cmd_line, m);
		if (!new_token)
			return (tkclear(token), NULL);
		else
			tk_lstadd_back(token, new_token);
		while (ft_isspace(*cmd_line))
			cmd_line++;
	}
	free(m->cmd_line);
	m->cmd_line = NULL;
	return (*token);
}
// core routine for the tokenizer, scan each part of the cmd line
// and give to each of them a type of tokens (identifier, separator,...)
