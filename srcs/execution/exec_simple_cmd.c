/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/08 16:14:36 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_exec_child(t_node *node) 
{
	
}

// Réinitialise stdin à la valeur initiale

void	reset_stds(bool piped) 
{
	if (piped) 
	{
		return;
	}
	dup2(g_minishell.stdin, 0);
	dup2(g_minishell.stdout, 1);
}

int	exec_simple_cmd(t_node *node, bool piped) 
{
	int tmp_status;

	if (!node->expanded_args) 
	{
		// Gérer les cas spéciaux (par exemple, commandes intégrées sans arguments (pwd))
		ft_reset_stds(piped);
		return tmp_status;
	}
	if (is_builtin(node->expanded_args[0])) 
	{
		tmp_status = exec_builtin(node);
		ft_reset_stds(piped);
		return tmp_status;
	}
	else
    	return ft_exec_child(node);
}
