/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:56 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/07 12:44:56 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#include "minishell.h"

static int	exec_builtin(t_node *node) 
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args[1]));
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_env());
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(args[0], "export") == 0)
		return (ft_export(args));
	if (ft_strcmp(args[0], "unset") == 0)
		return (ft_unset(args));
	ft_exit(args);
	return (ENO_GENERAL);
}

bool	is_builtin(char *arg)
{
	if (!arg)
		return (false);
	if (!ft_strcmp(arg, "echo")
		|| !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "exit")
		|| !ft_strcmp(arg, "pwd")
		|| !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env"))
		return (true);
	return (false);
}

static int	ft_exec_child(t_node *node) 
{
    // Exécuter un processus enfant et retourner le statut approprié
}

// Réinitialise stdin à la valeur initiale

void reset_stds(bool piped) 
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

    // Sinon, exécuter un processus enfant
    return ft_exec_child(node);
}
