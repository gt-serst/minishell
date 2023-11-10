/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:01:12 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/20 16:50:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	tmp;

	tmp = 0;
	while (s[tmp] != '\0')
		tmp++;
	return (tmp);
}

int	strchr_mod(char *s, int c)
{
	int		tmp;
	char	chr;

	if (!s)
		return (0);
	tmp = 0;
	chr = (char)c;
	while (s[tmp] != '\0' && s[tmp] != chr)
		tmp++;
	if (s[tmp] == chr)
		return (++tmp);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	int		tmp;
	char	*ptr;

	tmp = 0;
	while (s1[tmp] != '\0')
		tmp++;
	ptr = malloc(sizeof(char) * (tmp + 1));
	if (!ptr)
		return (NULL);
	tmp = 0;
	while (s1[tmp] != '\0')
	{
		ptr[tmp] = s1[tmp];
		tmp++;
	}
	ptr[tmp] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	tmp;
	size_t	size;
	char	*substr;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || start > (unsigned int)ft_strlen(s))
	{
		substr = ft_strdup("");
		return (substr);
	}
	size = 0;
	while (size < len && s[start + size] != '\0')
		size++;
	substr = (char *)malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	tmp = 0;
	while (tmp < len && s[start])
		substr[tmp++] = s[start++];
	substr[tmp] = '\0';
	return (substr);
}

char	*strjoin_mod(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}
