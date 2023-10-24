/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:58:21 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 16:09:15 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
}

char	*skip_quotes(char *cmd_line)
{
}
