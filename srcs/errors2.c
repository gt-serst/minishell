/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:44:38 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/27 14:09:29 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_str_err(t_err_type type, t_minishell *m)
{
	if (type == E_MEM)
	{
		m->err_code = 12;
		return ("bash: malloc allocation failed");
	}
	else if (type == E_TOO_MANY_ARGS)
	{
		m->err_code = 4;
		return ("bash: exit: too many arguments");
	}
	else if (type == E_SYNTAX)
	{
		m->err_code = 5;
		return ("bash: syntax error");
	}
	return ("bash: error undefined");
}

void	error(t_err_type type, char *token, char *cmd, t_minishell *m)
{
	if (type == E_UNEXP_TOK)
	{
		m->err_code = 258;
		unexp_tok_err_message(token);
	}
	else if (type == E_QUOTES)
	{
		m->err_code = 0;
		quotes_err_message(token);
	}
	else if (type == E_FILE)
	{
		m->err_code = 1;
		file_err_message(cmd);
	}
	else if (type == E_CMD_NOT_FOUND)
	{
		m->err_code = 127;
		cmd_err_message(cmd);
	}
	else if (type == E_NUM_MANDATORY)
	{
		m->err_code = 255;
		cmd_err_message(cmd);
	}
	else
		ft_putstr_fd(get_str_err(type, m), 2);
}

void	num_mandatory_err_message(char *cmd)
{
	ft_putstr_fd("bash: exit: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

void	cmd_err_message(char *cmd)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
}
