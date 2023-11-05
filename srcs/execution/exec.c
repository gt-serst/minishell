/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:55 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/05 16:06:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_ast(t_node *node)
{
	if (!node)
		return ;
	if (recursive_expander() == true)
	{
		if (recursive_redir(node) == true)
		{
			if (node->type == N_CMD)
			{
				exec_simple_cmd();
			}
			else
				exec_pipe();
		}
	}
}
