/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 12:01:50 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size * sizeof(char) + 1);
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
	return (free(s1), free(s2), str);
}

char	*ft_strjoin_nl(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size + sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = '\n';
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (free(s1), str);
}

char	*ft_strjoin_char(char *s1, char *s2, char c)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size + sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = c;
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (free(s1), free(s2), str);
}

void	ft_free_array(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

// void	read_from_fd(t_node *node)
// {
// 	char	buffer[4096];
// 	int		len;

// 	if (node->type == N_PIPE)
// 	{
// 		while ((len = read(node->data.pipe.left->data.simple_cmd.fdin,
//		buffer, sizeof(buffer))) > 0)
// 		{
// 			if (strstr(buffer, "exit") != NULL)
// 				break ;
// 		}
// 		while ((len = read(node->data.pipe.left->data.simple_cmd.fdout,
//		buffer, sizeof(buffer))) > 0)
// 		{
// 			if (strstr(buffer, "exit") != NULL)
// 				break ;
// 		}
// 	}
// 	else
// 	{
// 		while ((len = read(node->data.simple_cmd.fdin,
//		buffer, sizeof(buffer))) > 0)
// 		{
// 			if (strstr(buffer, "exit") != NULL)
// 				break;
// 		}
// 		while ((len = read(node->data.simple_cmd.fdout,
//		buffer, sizeof(buffer))) > 0)
// 		{
// 			if (strstr(buffer, "exit") != NULL)
// 				break;
// 		}
// 	}
// }
