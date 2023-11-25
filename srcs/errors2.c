/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:44:38 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/25 23:04:14 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_str_err(t_err_type type)
{
	if (type == E_MEM)
		return ("bash: malloc allocation failed\n");
	else if (type == E_TOO_MANY_ARGS)
		return ("bash: exit: too many arguments\n");
	else if (type == E_SYNTAX)
		return ("bash: syntax error\n");
	return ("bash: error undefined\n");
}

void	error(t_err_type type, char *token, char *cmd)
{
	if (type == E_UNEXP_TOK)
	{
		ft_set_exit_val(E_UNEXP_TOK);
		unexp_tok_err_message(token);
	}
	else if (type == E_QUOTES)
	{
		ft_set_exit_val(E_QUOTES);
		quotes_err_message(token);
	}
	else if (type == E_FILE)
	{
		ft_set_exit_val(E_FILE);
		file_err_message(cmd);
	}
	else if (type == E_FILE_LENGTH)
	{
		ft_set_exit_val(E_FILE_LENGTH);
		file_length_err_message(cmd);
	}
	else if (type == E_CMD_NOT_FOUND)
	{
		ft_set_exit_val(E_CMD_NOT_FOUND);
		cmd_err_message(cmd);
	}
	else if (type == E_NUM_MANDATORY)
	{
		ft_set_exit_val(E_NUM_MANDATORY);
		cmd_err_message(cmd);
	}
	else
		ft_putstr_fd(get_str_err(type), 2);
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
