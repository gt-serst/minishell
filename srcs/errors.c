/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:48:53 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/03 12:25:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_message(char *s)
{
	ft_putstr_fd(s, 2);
	exit (EXIT_FAILURE);
}

void	quotes_err_message(char c)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}

void	set_parsing_err(t_parsing_err_type type)
{
	g_minishell.parsing_err.type = type;
}

void	set_expand_err(t_expand_err_type type)
{
	g_minishell.expand_err.type = type;
}

t_node	*parsing_err_handler(void)
{// determine the reason of the error and return the correct err code to parser function
	if (g_minishell.parsing_err.type == PE_MEM)
		g_minishell.err_code = 12;
	else if (g_minishell.parsing_err.type == PE_SYNTAX)
		g_minishell.err_code = 258;
	return (NULL);
}
