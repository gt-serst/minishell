/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:03:39 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/13 16:42:03 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	quotes_err_message(char c)
{
	ft_putstr_fd("bash: unexpected EOF while looking for matching '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}
