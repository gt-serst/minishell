/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:40:40 by mde-plae          #+#    #+#             */
/*   Updated: 2024/03/22 11:58:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	is_option_n(char *s)
{
	int	i;

	i = 0;
	if (s[0] != '-')
		return (0);
	i++;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	is_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == '$')
			ft_putstr_fd(ft_itoa(getpid()), 1);
		else
			ft_putstr_fd(ft_substr(s, i - 1, ft_strlen(s)), 1);
		i++;
	}
}

int	ft_echo(char **args)
{
	int		i;
	int		j;
	bool	no_newline;

	i = 1;
	no_newline = false;
	while (args[i] && is_option_n(args[i]))
	{
		no_newline = true;
		i++;
	}
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '$')
			is_dollar(args[i]);
		else
			ft_putstr_fd(args[i], 1);
		if (args[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!no_newline)
		ft_putstr_fd("\n", 1);
	return (0);
}
