/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:58 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/10 18:09:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit\n", 1);
}
