/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:40:40 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/06 10:59:25 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool is_option_n(char *s) 
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

int ft_echo(char **args) 
{
    int i;
    bool no_newline;
	
	i = 1;
	no_newline = false;
    while (args[i] && is_option_n(args[i])) 
	{
        no_newline = true;
        i++;
    }
    while (args[i]) 
	{
        ft_printf("%s", args[i]);
        if (args[i + 1] != NULL) 
		{
            ft_printf(" ");
        }
        i++;
    }
    if (!no_newline) 
	{
        ft_printf("\n");
    }
    return 0;
}
