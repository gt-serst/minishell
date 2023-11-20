/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/20 11:36:42 by gt-serst         ###   ########.fr       */
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
		printf("New cmd\n");
		i = 0;
		while (node->data.simple_cmd.args[i])
			printf("%s\n", node->data.simple_cmd.args[i++]);
	}
	else
	{
		printf("New pipe\n");
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
		printf("Cmd expanded\n");
		i = 0;
		while (node->data.simple_cmd.expanded_args[i])
			printf("%s\n", node->data.simple_cmd.expanded_args[i++]);
	}
	else
	{
		printf("Pipe detected\n");
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

void	read_from_fd(t_node *node)
{
	char	buffer[4096];
	int		len;

	if (node->type == N_PIPE)
	{
		printf("Pipe\n");
		while ((len = read(node->data.pipe.left->data.simple_cmd.fdin, buffer, sizeof(buffer))) > 0)
		{
			printf("Content in Fdin %s\n", buffer);
			if (strstr(buffer, "exit") != NULL)
				break;
		}
		while ((len = read(node->data.pipe.left->data.simple_cmd.fdout, buffer, sizeof(buffer))) > 0)
		{
			printf("Content in Fdout %s\n", buffer);
			if (strstr(buffer, "exit") != NULL)
				break;
		}
	}
	else
	{
		printf("Cmd\n");
		printf("%s\n", node->data.simple_cmd.expanded_args[0]);
		printf("Fdin %d\n", node->data.simple_cmd.fdin);
		while ((len = read(node->data.simple_cmd.fdin, buffer, sizeof(buffer))) > 0)
		{
			printf("Content in Fdin %s\n", buffer);
			if (strstr(buffer, "exit") != NULL)
				break;
		}
		printf("Fdout %d\n", node->data.simple_cmd.fdout);
		while ((len = read(node->data.simple_cmd.fdout, buffer, sizeof(buffer))) > 0)
		{
			printf("Content in Fdout %s\n", buffer);
			if (strstr(buffer, "exit") != NULL)
				break;
		}
	}
}
