/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 12:12:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	separator_type(char c)
{// retrieve the type of separator and called the separator_handler
	if (c == '<')
		separator_handler(c, "T_LESS");
	if (c == '>')
		separator_handler(c, "T_REAT");
	if (c == '<<')
		separator_handler(c, "T_DESS");
	if (c == '>>')
		separator_handler(c, "T_DGREAT");
	if (c == '|')
		separator_handler(c, "T_PIPE");
	if (c == '(')
		separator_handler(c, "T_LPAREN");
	if (c == ')')
		separator_handler(c, "T_PPAREN");
	//separator_handler(cmd_line);
}

void	identifier_handler(char c)
{// create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	
	//tk = tk_new(content);
	//tkadd_back(token, tk);
}

void	separator_handler(char c, char *type)
{//create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	(void)c;
	//tk = tk_new(content);
	//tkadd_back(token, tk);
}
