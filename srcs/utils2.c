/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:17 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/24 09:55:30 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_token(t_token *token)
{
	printf("Try to print token\n");
	if (!token)
		return ;
	while (token)
	{
		printf("%s\n", token->value);
		token = token->next;
	}
}

void	ft_print_ast(t_node *node)
{
	int	i;

	printf("Try to print ast\n");
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

	printf("Try to print expanded ast\n");
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
