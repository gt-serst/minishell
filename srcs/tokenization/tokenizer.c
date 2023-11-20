/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:37:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/20 22:44:13 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	unexpected_token(char c)
{
	if (c == ';')
	{
		ft_putstr_fd("bash: syntax error near unexpected token `;'\n", 2);
		return (true);
	}
	else if (c == '\\')
	{
		ft_putstr_fd("bash: syntax error near unexpected token `\\'\n", 2);
		return (true);
	}
	return (false);
}

t_token	*tokenizer()
{// core routine for the tokenizer, scan each part of the cmd line and give to each of them a type of tokens (identifier, separator,...)
	t_token **token;
	t_token *new_token;
	char	*cmd_line;

	token = &g_minishell.token;
	cmd_line = g_minishell.cmd_line;
	while (ft_isspace(*cmd_line))
		cmd_line++;
	while (*(cmd_line))
	{
		if (ft_ismetachar(*cmd_line))
			new_token = separator_handler(&cmd_line); //get the right index in the line we are
		else
			new_token = identifier_handler(&cmd_line); //get the right index in the line we are
		if (g_minishell.token_err.type)
			return (tkclear(token), NULL);
		else
			tk_lstadd_back(token, new_token);
		while (ft_isspace(*cmd_line))
			cmd_line++;
	}
	free(g_minishell.cmd_line);
	g_minishell.cmd_line = NULL;
	return (*token);
}
