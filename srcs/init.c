/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:06:38 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/18 19:28:59 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_env(char **envp)
{//init env variables and all variables from our shell to correctly start
	if (!envp)
		return (ft_exit_message("Error: Env variables not found\n"));
	ft_memset(&g_minishell, 0, sizeof(t_minishell));
	g_minishell.environ = envp;
	envlst_init();
	// g_minishell.in = dup(0);
	// g_minishell.out = dup(1);
	tcgetattr(STDIN_FILENO, &g_minishell.original_term);
}
