/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:56:39 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 17:36:07 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	unexp_tok_err_message(char *token)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	ft_putstr_fd(token, 2);
	ft_putstr_fd("'\n", 2);
}

void	file_err_message(char *file)
{
	if (errno == 13)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}

void	file_length_err_message(char *file)
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
