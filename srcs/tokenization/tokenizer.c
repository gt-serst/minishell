/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:37:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 10:30:04 by gt-serst         ###   ########.fr       */
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

t_token	*tokenizer(char *line)
{// core routine for the tokenizer, scan each part of the cmd line and give to each of them a type of tokens (identifier, separator,...)
	t_token	*token;
	t_token	*new_token;
	char	*cmd_line;

	cmd_line = line;
	while (ft_isspace(*cmd_line))
		cmd_line++;
	while (*(cmd_line))
	{
		if (ft_ismetachar(*cmd_line))
			new_token = separator_handler(&cmd_line); //get the right index in the line we are
		else
			new_token = identifier_handler(&cmd_line); //get the right index in the line we are
		if (!new_token)
			return (tkclear(&token), NULL);
		else
			tk_lstadd_back(&token, new_token);
		while (ft_isspace(*cmd_line))
			cmd_line++;
	}
	free(line);
	line = NULL;
	return (token);
}
