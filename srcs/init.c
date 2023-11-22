/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:06:38 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/22 17:04:54 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_env(t_minishell *m, char **envp)
{//init env variables and all variables from our shell to correctly start
	if (!envp)
		return (ft_exit_message("bash: env variables not found\n"));
	ft_memset(m, 0, sizeof(t_minishell));
	m->env = envp;
	printf("Hello\n");
	envlst_init(m->envlst, m->env);
	m->input = dup(0);
	m->output = dup(1);
	m->err_code = 0;
	tcgetattr(STDIN_FILENO, &m->original_term);
}
