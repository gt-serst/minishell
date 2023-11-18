/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:04:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/18 18:51:50 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_expand_err(t_expand_err_type type)
{
	g_minishell.expand_err.type = type;
}

void	expanding_err_handler(void)
{
	if (g_minishell.expand_err.type == EE_MEM)
	{
		ft_putstr_fd("bash: malloc allocation failed\n", 2);
		g_minishell.err_code = 12;
	}
	else if (g_minishell.expand_err.type == EE_OPEN)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		g_minishell.err_code = errno;
	}
	ft_bzero(&g_minishell.expand_err, sizeof(t_expand_err));
}
