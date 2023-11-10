/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:04:16 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/10 16:07:40 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_parsing_err(t_parsing_err_type type)
{
	g_minishell.parsing_err.type = type;
}

void	parsing_err_handler(void)
{// determine the reason of the error and return the correct err code to parser function
	if (g_minishell.parsing_err.type == PE_MEM)
	{
		ft_putstr_fd("bash: malloc allocation failed\n", 2);
		g_minishell.err_code = 12;
	}
	else if (g_minishell.parsing_err.type == PE_SYNTAX)
	{
		ft_putstr_fd("bash: syntax error\n, 2");
		g_minishell.err_code = 258;
	}
	ft_bzero(&g_minishell.parsing_err, sizeof(t_parsing_err));
}
