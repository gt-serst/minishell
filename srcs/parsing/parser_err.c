/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:56 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/27 15:29:23 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_parsing_err(t_parsing_err_type type)
{
	g_minishell.parsing_err.type = type;
}

t_node	*parsing_err_handler(void)
{// determine the reason of the error and return the correct err code to parser function
	if (g_minishell.parsing_err.type == E_MEM)
		g_minishell.err_code = 12;
	else if (g_minishell.parsing_err.type == E_SYNTAX)
		g_minishell.err_code = 258;
	return (NULL);
}
