/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/23 13:57:40 by gt-serst         ###   ########.fr       */
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

static int	exitnbr(t_minishell *m, char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	atoi_skip(str, &i, &sign);
	if (!ft_isnumber(str + i))
	{
		error(E_NUM_MANDATORY, NULL, str + i);
		shell_cleaner(m);
		exit(m->err_code);
	}
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		if (result > LONG_MAX)
		{
			error(E_NUM_MANDATORY, NULL, (char*)result);
			shell_cleaner(m);
			exit(m->err_code);
		}
		i++;
	}
	return ((result * sign) % 256);
}

void	ft_exit(t_minishell *m, char **args, bool piped)
{
	int	err_code;

	err_code = m->err_code;
	if (args[1])
	{
		if (args[2] && ft_isnumber(args[1]))
		{
			error(E_TOO_MANY_ARGS, NULL, NULL);
			shell_cleaner(m);
			return ;
		}
		else
			err_code = exitnbr(m, args[1]);
	}
	close_io(m, piped);
	shell_shutdown(m);
	exit(err_code);
}
