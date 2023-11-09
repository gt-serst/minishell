/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/09 12:00:15 by mde-plae         ###   ########.fr       */
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
	int					exit_s;
	unsigned long long	result;
	
	i = 0;
	sign = 1;
	atoi_skip(str, &i, &sign);
	if (!ft_isnumber(s + i))
	{
		exit_s = ft_err_msg()
		clean_minishell();
		exit(exit_s);
	}
	resut = 0;
	while (s[i])
	{
		result = (result * 10) + (s[i] - '0');
		if (result > LONG_MAX)
		{
			exit_s = ft_err_msg();
			ft_clean_ms();
			exit(exit_s);
		}
		i++;
	}
	return ((result * sign) % 256);
}

void	ft_exit(char **args)
{
	int	exit_s;

	exit_s = g_minishell.exit_s;
	if (args[1])
	{
		if (args[2] && ft_isnumber(args[1]))
		{
			exit_s = error_msg(42, "too many arguments");
			clean_minishell();
			exit(exit_s);
		}
		else
			exit_s = exitnbr(args[1]);
	}
	clean_minishell();
	exit(exit_s);
}