/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:37:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 12:30:22 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_isspace(char	c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

bool	ft_ismetachar(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '(' || c == ')')
		return (1);
	return (0);
}

void	tokenizer(t_minishell *m)
{// core routine for the tokenizer, scan each part of the cmd line and give to each of them a type of tokens (identifier, separator,...)
	while (*(m->cmd_line))
	{
		if (ft_isspace(*(m->cmd_line)))
			(m->cmd_line)++;
		else if (ft_ismetachar(*(m->cmd_line)))
			separator_type(m->cmd_line); //get the right index in the line we are
		else
			identifier_handler(m->cmd_line); //get the right index in the line we are
	}
}
