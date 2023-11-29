/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 18:06:31 by gt-serst         ###   ########.fr       */
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

static char	*get_unexp_char_token(char token)
{
	if (token == ';')
		return (";");
	return ("\\");
}

t_token	*separator_handler(char	**cmd_line, t_minishell *m)
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
		return (error(E_MEM, NULL, NULL, m), NULL);
	*cmd_line += i;
	if (ft_strcmp(substr, "<") == 0)
		return (new_tk(substr, T_INPUT, m));
	else if (ft_strcmp(substr, ">") == 0)
		return (new_tk(substr, T_OUTPUT, m));
	else if (ft_strcmp(substr, "<<") == 0)
		return (new_tk(substr, T_HEREDOC, m));
	else if (ft_strcmp(substr, ">>") == 0)
		return (new_tk(substr, T_APPEND, m));
	else if (ft_strcmp(substr, "|") == 0)
		return (new_tk(substr, T_PIPE, m));
	else
		return (error(E_UNEXP_TOK, get_unexp_str_token(substr), NULL, m), NULL);
}
// malloc allocation in token
// retrieve the type of separator and called the separator_handler

t_token	*identifier_handler(char **cmd_line, t_minishell *m)
{
	size_t	i;
	char	*tmp;
	char	*substr;

	i = 0;
	tmp = *cmd_line;
	while (tmp[i] && !ft_ismetachar(tmp[i]) && !ft_isspace(tmp[i]))
	{
		if (ft_isquotes(tmp[i]) && !skip_quotes(tmp, &i, m))
			return (NULL);
		if (unexpected_token(tmp[i]))
			return (error(E_UNEXP_TOK,
					get_unexp_char_token(tmp[i]), NULL, m), NULL);
		i++;
	}
	substr = ft_substr(*cmd_line, 0, i);
	if (!substr)
		return (error(E_MEM, NULL, NULL, m), NULL);
	*cmd_line += i;
	return (new_tk(substr, T_IDENTIFIER, m));
}

// malloc allocation in substr & token
// create a tk and add it to the linkded list
// and then allocate a type of token to the cmd part
