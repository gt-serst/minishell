/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:49:10 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/03 14:53:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			tmp;
	unsigned char	*str1;
	unsigned char	*str2;

	tmp = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[tmp] != '\0' || str2[tmp] != '\0'))
	{
		if (str1[tmp] != str2[tmp])
			return (str1[tmp] - str2[tmp]);
		tmp++;
	}
	return (0);
}
