/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/13 15:53:25 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	atoi_skip(char *s, int *i, int *sign)
{
	while (s[*i] && s[*i] == ' ')
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

static int	exitnbr(char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	atoi_skip(str, &i, &sign);
	if (!ft_isnumber(str + i))
	{
		set_exec_err(EXE_NUM_MANDATORY);
		shell_cleaner();
		exit(g_minishell.err_code);
	}
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		if (result > LONG_MAX)
		{
			set_exec_err(EXE_NUM_MANDATORY);
			shell_cleaner();
			exit(g_minishell.err_code);
		}
		i++;
	}
	return ((result * sign) % 256);
}

void	ft_exit(char **args)
{
	int	err_code;

	err_code = g_minishell.err_code;
	if (args[1])
	{
		if (args[2] && ft_isnumber(args[1]))
		{
			set_exec_err(EXE_TOO_MANY_ARGS); //exit code 42
			shell_cleaner();
			return ;
		}
		else
			err_code = exitnbr(args[1]);
	}
	shell_cleaner();
	exit(err_code);
}
