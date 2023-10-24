/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 12:32:49 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	separator_type(char	*cmd_line)
{// retrieve the type of separator and called the separator_handler
	int		count;
	char	*substr;

	count = 0;
	while (!ft_isspace(cmd_line))
		count++;
	substr = ft_substr(cmd_line, 0, count); //free in substr
	if (substr == "<")
		separator_handler(substr, "T_LESS");
	else if (substr == ">")
		separator_handler(substr, "T_REAT");
	else if (substr == "<<")
		separator_handler(substr, "T_DESS");
	else if (substr == ">>")
		separator_handler(substr, "T_DGREAT");
	else if (substr == "|")
		separator_handler(substr, "T_PIPE");
	else if (substr == "(")
		separator_handler(substr, "T_LPAREN");
	else if (substr == ")")
		separator_handler(substr, "T_PPAREN");
	else
		return (ft_exit_message("Error: type of separator not found"));
}

void	identifier_handler(char *cmd_line)
{// create a tk and add it to the linkded list and then allocate a type of token to the cmd part

	//tk = tk_new(content);
	//tkadd_back(token, tk);
}

void	separator_handler(char *sep, char *type)
{//create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	(void)c;
	//tk = tk_new(content);
	//tkadd_back(token, tk);
}
