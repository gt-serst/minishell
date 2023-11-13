/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:05:35 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/13 16:41:04 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	export_err_message(char *s)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

void	set_exec_err(t_exec_err_type type)
{
	g_minishell.exec_err.type = type;
}

void	exec_err_handler(void)
{
	ft_putstr_fd("bash: execution error\n", 2);
	g_minishell.err_code = 127;
	ft_bzero(&g_minishell.exec_err, sizeof(t_exec_err));
}
