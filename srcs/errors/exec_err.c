/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:05:35 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/10 16:07:29 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_exec_err(t_exec_err_type type)
{
	g_minishell.exec_err.type = type;
}

void	exec_err_handler(void)
{
	ft_pustr_fd("bash: execution error\n", 2);
	g_minishell.err_code = 127;
	ft_bzero(&g_minishell.exec_err, sizeof(t_exec_err));
}
