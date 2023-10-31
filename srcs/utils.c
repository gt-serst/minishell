/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/31 09:54:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_token(t_token **t)
{
	t_token	*head;

	head = (*t);
	while (head)
	{
		printf("Value %s Type %d\n", head->value, head->type);
		head = head->next;
	}
}

void	ft_print_token_reverse(t_token **t)
{
	t_token	*tail;

	tail = (*t);
	while (tail->next)
		tail = tail->next;
	while (tail)
	{
		printf("%s\n", tail->value);
		tail = tail->prev;
	}
}

void	ft_print_ast(t_node *node)
{
	t_node *head;

	if (!node)
		return ;
	head = node;
	if (head->type == N_PIPE)
	{
		printf("Pipe\n");
		ft_print_ast(head->left);
		ft_print_ast(head->right);
	}
	else
		printf("Elem %s\n", head->args);
}

void	ft_print_io_list(t_io_node **io_lst)
{
	t_io_node	*head;

	head = *io_lst;
	while(head)
	{
		printf("Value %s\n", head->value);
		head = head->next;
	}
}

char	*join_with_char(char *s1, char *s2, char c)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = c;
	i = 0;
	while (s2[i])
		str[j++] = *s2++;
	str[j] = '\0';
	return (str);
}
