/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:17:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/08 16:33:02 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(char **args)
{
	int	exit_s;

	exit_s = g_minishell.exit_s;
	if (args[1])
	{
		if (args[2] && ft_isnumber(args[1]))
		{
			exit_s = error_msg()
		}
		
	}
}