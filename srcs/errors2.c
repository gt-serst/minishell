/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:44:38 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/29 13:15:02 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_str_err(t_err_type type)
{
	if (type == E_MEM)
		return ("bash: malloc allocation failed\n");
	else if (type == E_TOO_MANY_ARGS)
		return ("bash: exit: too many arguments\n");
	return ("bash: error undefined\n");
}

void	set_err_code(t_err_type type, t_minishell *m)
{
	if (type == E_MEM)
		m->err_code = 12;
	else if (type == E_UNEXP_TOK)
		m->err_code = 258;
	else if (type == E_QUOTES)
		m->err_code = 1;
	else if (type == E_FILE)
		m->err_code = 1;
	else if (type == E_FILE_LENGTH)
		m->err_code = 1;
	else if (type == E_TOO_MANY_ARGS)
		m->err_code = 1;
	else if (type == E_CMD_NOT_FOUND)
		m->err_code = 127;
	else if (type == E_PATH_NOT_FOUND)
		m->err_code = 127;
	else if (type == E_NUM_MANDATORY)
		m->err_code = 255;
}

void	error(t_err_type type, char *token, char *cmd, t_minishell *m)
{
	set_err_code(type, m);
	if (type == E_UNEXP_TOK)
		unexp_tok_err_message(token);
	else if (type == E_QUOTES)
		quotes_err_message(token);
	else if (type == E_FILE || type == E_PATH_NOT_FOUND)
		file_err_message(cmd);
	else if (type == E_FILE_LENGTH)
		file_length_err_message(cmd);
	else if (type == E_CMD_NOT_FOUND || type == E_NUM_MANDATORY)
		cmd_err_message(cmd);
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
