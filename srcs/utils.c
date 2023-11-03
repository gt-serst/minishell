/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/03 11:48:59 by gt-serst         ###   ########.fr       */
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
