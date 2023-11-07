/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/07 14:22:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_ast(t_node *node)
{
	int	i;

	if (node->type == N_CMD)
	{
		i = 0;
		printf("New cmd, Type %d\n", node->type);
		while (node->data.simple_cmd.args[i])
			printf("Arg %s\n", node->data.simple_cmd.args[i++]);
	}
	else
	{
		printf("New pipe, Type %d\n", node->type);
		if (node->data.pipe.left != NULL)
			ft_print_ast(node->data.pipe.left);
		if (node->data.pipe.right != NULL)
			ft_print_ast(node->data.pipe.right);
	}
}

char	*ft_strjoin_mod2(char *s1, char *s2)
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
	free(s1);
	return (str);
}


