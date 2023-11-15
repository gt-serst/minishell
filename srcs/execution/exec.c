/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:55 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/15 12:13:39 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_node(t_node *node)
{
	if (node->type == N_CMD)
	{
		//ft_print_expanded_ast(node);
		printf("Command before exec %s\n", node->data.simple_cmd.expanded_args[0]);
		return (exec_simple_cmd(node));
	}
	else
	{
		printf("JE RENTRE DANS LA PIPELINE\n");
		return (exec_pipeline(node));
	}
}

int	exec_ast(t_node *node)
{
	printf("Type de noeud %d\n\n", node->type);
	printf("JE RENTRE DANS L'EXPANDER\n");
	if (!node)
		return (EXIT_FAILURE);
	if (recursive_expander(node) == true)
	{
		printf("JE RENTRE DANS LES REDIRECTIONS\n");
		if (recursive_redir(node) == true)
		{
			printf("JE RENTRE DANS L'EXEC\n");
			return (exec_node(node));
		}
	}
	return (EXIT_FAILURE);
}
