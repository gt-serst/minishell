/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:48:53 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 16:15:11 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_message(char *s)
{
	ft_putstr_fd(s, 2);
	exit (EXIT_FAILURE);
}

void	quotes_err_message(char c)
{
}
