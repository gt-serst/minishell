/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:03:39 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/14 10:52:07 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_token_err(t_token_err_type type)
{
	g_minishell.token_err.type = type;
}

void	token_err_handler(void)
{
	if (g_minishell.token_err.type = TE_MEM)
	{
		ft_putstr_fd("bash: malloc allocation failed\n", 2);
		g_minishell.err_code = 12;
	}
	ft_bzero(&g_minishell.token_err, sizeof(t_token_err));
}

void	quotes_err_message(char c)
{
	ft_putstr_fd("bash: unexpected EOF while looking for matching '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}
