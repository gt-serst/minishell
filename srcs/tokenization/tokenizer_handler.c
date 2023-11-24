/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 11:59:10 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_unexp_str_token(char *token)
{
	if (strncmp(token, "<<<", 3) == 0)
	{
		if (strcmp(token, "<<<") == 0)
			return ("<");
		else if (strcmp(token, "<<<<") == 0)
			return ("<<");
		else
			return ("<<<");
	}
	if (strncmp(token, ">>>", 3) == 0)
	{
		if (strcmp(token, ">>>") == 0)
			return (">");
		else
			return (">>");
	}
	if (strcmp(token, "||") == 0)
		return ("|");
	return ("||");
}

/*
static char	*get_unexp_char_token(char token)
{
	if (token == ';')
		return (";");
	else if (token == '\\')
		return ("\\");
}
*/

t_token	*separator_handler(char	**cmd_line)
{
	size_t	i;
	char	*substr;
	char	*tmp;

	i = 0;
	tmp = *cmd_line;
	while (tmp[i] && ft_ismetachar(tmp[i]) && !ft_isspace(tmp[i]))
		i++;
	substr = ft_substr(tmp, 0, i);
	if (!substr)
		return (error(E_MEM, NULL, NULL), NULL);
	*cmd_line += i;
	if (ft_strcmp(substr, "<") == 0)
		return (new_tk(substr, T_INPUT));
	else if (ft_strcmp(substr, ">") == 0)
		return (new_tk(substr, T_OUTPUT));
	else if (ft_strcmp(substr, "<<") == 0)
		return (new_tk(substr, T_HEREDOC));
	else if (ft_strcmp(substr, ">>") == 0)
		return (new_tk(substr, T_APPEND));
	else if (ft_strcmp(substr, "|") == 0)
		return (new_tk(substr, T_PIPE));
	else
		return (error(E_UNEXP_TOK, get_unexp_str_token(substr), NULL), NULL);
}
// malloc allocation in token
// retrieve the type of separator and called the separator_handler

t_token	*identifier_handler(char **cmd_line)
{
	size_t	i;
	char	*substr;
	char	*tmp;

	i = 0;
	tmp = *cmd_line;
	while (tmp[i] && !ft_ismetachar(tmp[i]) && !ft_isspace(tmp[i]))
	{
		if (ft_isquotes(tmp[i]))
		{
			if (!skip_quotes(tmp, &i))
				return (NULL);
		}
		else
		{
			if (unexpected_token(tmp[i]))
				return (error(E_UNEXP_TOK, &tmp[i], NULL), NULL);
			i++;
		}
	}
	substr = ft_substr(*cmd_line, 0, i);
	if (!substr)
		return (error(E_MEM, NULL, NULL), NULL);
	*cmd_line += i;
	return (new_tk(substr, T_IDENTIFIER));
}
// malloc allocation in substr & token
// create a tk and add it to the linkded list
// and then allocate a type of token to the cmd part
