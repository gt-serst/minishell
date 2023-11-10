/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:37:44 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/03 11:10:29 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *s)
{
	int	print_length;
	int	tmp;

	if (!s)
		return (write(1, "(null)", 6));
	print_length = 0;
	tmp = 0;
	while (s[tmp] != '\0')
		print_length += ft_print_char(s[tmp++]);
	return (print_length);
}
