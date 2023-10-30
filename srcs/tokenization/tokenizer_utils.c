/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:58:21 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/25 14:16:16 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_isspace(char	c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

bool	ft_ismetachar(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '(' || c == ')')
		return (true);
	return (false);
}

bool	ft_isquotes(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}

void	skip_spaces(char **cmd_line)
{
	while (**cmd_line && ft_isspace(**cmd_line))
		(*cmd_line)++;
}

bool	skip_quotes(char **cmd_line)
{
	char	quote;

	quote = **cmd_line;
	while (**cmd_line && !ft_isquotes(**cmd_line))
		(*cmd_line)++;
	if (**cmd_line == quote)
	{
		(*cmd_line)++;
		return (true);
	}
	else
		return (false);
}
