/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:06:38 by gt-serst          #+#    #+#             */
/*   Updated: 2024/04/29 15:01:26 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_env(t_minishell *m, char **envp)
{
	if (!envp)
		return (ft_exit_message("bash: env variables not found\n"));
	ft_memset(m, 0, sizeof(t_minishell));
	m->env = envp;
	envlst_init(&m->envlst, m->env);
	tcgetattr(STDIN_FILENO, &m->original_term);
}
// init env variables and all variables from our shell to correctly start
