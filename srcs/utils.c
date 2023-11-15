/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/15 16:47:17 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_ast(t_node *node)
{
	int	i;

	if (!node)
		return ;
	if (node->type == N_CMD)
	{
		i = 0;
	}
	else
	{
		if (node->data.pipe.left != NULL)
			ft_print_ast(node->data.pipe.left);
		if (node->data.pipe.right != NULL)
			ft_print_ast(node->data.pipe.right);
	}
}

void	ft_print_expanded_ast(t_node *node)
{
	int	i;

	if (!node)
		return ;
	if (node->type == N_CMD)
	{
		i = 0;
	}
	else
	{
		if (node->data.pipe.left != NULL)
			ft_print_ast(node->data.pipe.left);
		if (node->data.pipe.right != NULL)
			ft_print_ast(node->data.pipe.right);
	}
}

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
