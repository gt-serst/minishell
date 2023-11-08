/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:37:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/08 12:32:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	check_unexpected_token(char *cmd_line)
{
	if (*cmd_line == ';')
	{
		ft_putstr_fd("bash: syntax error near unexpected token `;'\n", 2);
		return (true);
	}
	return (false);
}

t_token	*tokenizer()
{// core routine for the tokenizer, scan each part of the cmd line and give to each of them a type of tokens (identifier, separator,...)
	t_token *t;
	t_token *token;
	char	*cmd_line;

	t = g_minishell.tokens;
	cmd_line = g_minishell.cmd_line;
	while (ft_isspace(*cmd_line))
		cmd_line++;
	while (*(cmd_line))
	{
		if (check_unexpected_token(cmd_line))
			 return (tkclear(&t), NULL);
		else if (ft_ismetachar(*(cmd_line)))
			token = separator_handler(&cmd_line); //get the right index in the line we are
		else
			token = identifier_handler(&cmd_line); //get the right index in the line we are
		if (!token)
			return (tkclear(&t), NULL);
		else
		{
			printf("Token %s\n", token->value);
			tkadd_back(&t, token);
		}
		while (ft_isspace(*cmd_line))
			cmd_line++;
	}
	free(g_minishell.cmd_line);
	g_minishell.cmd_line = NULL;
	return (t);
}
