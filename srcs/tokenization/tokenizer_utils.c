/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/23 18:10:35 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	separator_type(t_minishell *m)
{// retrieve the type of separator and called the separator_handler
	(void)m;
	// if (m->cmd_line == '<')
	// if (m->cmd_line == '>')
	// if (m->cmd_line == '<<')
	// if (m->cmd_line == '>>')
	// if (m->cmd_line == '|')
	// if (m->cmd_line == '(')
	// if (m->cmd_line == ')')
	//separator_handler(cmd_line);
}

void	identifier_handler(t_minishell *m)
{// create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	(void)m;
	//tk = tk_new(content);
	//tkadd_back(token, tk);
}

void	separator_handler(t_minishell *m)
{//create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	(void)m;
	//tk = tk_new(content);
	//tkadd_back(token, tk);
}
