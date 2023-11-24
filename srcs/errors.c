/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:56:39 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 12:14:03 by gt-serst         ###   ########.fr       */
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
		unexp_tok_err_message(token);
	else if (type == E_QUOTES)
		quotes_err_message(token);
	else if (type == E_FILE)
		file_err_message(cmd);
	else if (type == E_FILE_LONG)
		file_long_err_message(cmd);
	else if (type == E_CMD_NOT_FOUND)
		cmd_err_message(cmd);
	else if (type == E_NUM_MANDATORY)
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

void	unexp_tok_err_message(char *token)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
}

void	file_err_message(char *file)
{
	if (errno == 2)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (errno == 13)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
}

void	file_long_err_message(char *file)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": File name too long\n", 2);
}

void	quotes_err_message(char *s)
{
	ft_putstr_fd("bash: unexpected EOF while looking for matching '", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("'\n", 2);
}

void	ft_exit_message(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
}
