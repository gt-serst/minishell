/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:37:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/25 16:24:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*tokenizer(void)
{// core routine for the tokenizer, scan each part of the cmd line and give to each of them a type of tokens (identifier, separator,...)
	t_token	*t;
	char	*cmd_line;
	int		err;

	t = NULL;
	cmd_line = g_minishell.cmd_line;
	err = 1;
	while (*(cmd_line))
	{
		if (!err)
			return (tkclear(&t), NULL);
		if (ft_isspace(*cmd_line))
			skip_spaces(&cmd_line);
		else if (*(cmd_line) && ft_ismetachar(*(cmd_line)))
			err = separator_recognizer(&t, &cmd_line); //get the right index in the line we are
		else
			err = identifier_handler(&t, &cmd_line); //get the right index in the line we are
	}
	//free(cmd_line);
	g_minishell.cmd_line = NULL;
	ft_printlst(&t);
	return (t);
}
