/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:37:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 15:59:05 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokenizer(t_minishell *m)
{// core routine for the tokenizer, scan each part of the cmd line and give to each of them a type of tokens (identifier, separator,...)
	while (*(m->cmd_line))
	{
		while (*(m->cmd_line) && ft_isspace(*(m->cmd_line)))
			(m->cmd_line)++;
		if (*(m->cmd_line) && ft_ismetachar(*(m->cmd_line)))
			separator_recognizer(m, m->cmd_line); //get the right index in the line we are
		else if (*(m->cmd_line))
			identifier_handler(m, m->cmd_line); //get the right index in the line we are
		while (*(m->cmd_line) && !ft_isspace(*(m->cmd_line)))
			(m->cmd_line)++;
	}
	free(m->cmd_line);
	//ft_printlst(m);
	//ft_printlst_reverse(m);
}
