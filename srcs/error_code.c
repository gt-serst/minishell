/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:08:39 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/27 14:50:00 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	*ft_get_exit_val(void)
{
	static int	exit_val = 0;

	return (&exit_val);
}

void	ft_set_exit_val(int exit_value)
{
	*ft_get_exit_val() = exit_value;
}
