/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/10 15:44:52 by mde-plae         ###   ########.fr       */
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

void	atoi_skip(char *s, int *i, int *sign)
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
	int					err_code;
	unsigned long long	result;
	
	i = 0;
	sign = 1;
	atoi_skip(str, &i, &sign);
	if (!ft_isnumber(s + i))
	{
		err_code = ft_err_msg()
		clean_minishell();
		exit(err_code);
	}
	resut = 0;
	while (s[i])
	{
		result = (result * 10) + (s[i] - '0');
		if (result > LONG_MAX)
		{
			err_code = ft_err_msg();
			ft_clean_ms();
			exit(err_code);
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
			err_code = error_msg(42, "too many arguments");
			clean_minishell();
			exit(err_code);
		}
		else
			err_code = exitnbr(args[1]);
	}
	clean_minishell();
	exit(err_code);
}