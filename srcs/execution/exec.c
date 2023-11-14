/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:55 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/14 14:46:11 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_ast(t_node *node)
{
	if (!node)
		return ;
	if (recursive_expander(node) == true)
	{
		if (recursive_redir(node) == true)
		{
			if (node->type == N_CMD)
			{
				if (!exec_simple_cmd(node))
					return ;
			}
			else
				if (!exec_pipeline(node))
					return ;
		}
	}
	shell_cleaner();
}
