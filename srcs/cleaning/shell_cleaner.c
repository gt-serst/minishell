/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:12:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/13 16:02:33 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	envlst_cleaner(void)
{
	t_env	*envlst;
	t_env	*envlst_tofree;

	envlst = g_minishell.envlst;
	while (envlst)
	{
		envlst_tofree = envlst;
		envlst = envlst->next;
		free(envlst_tofree);
	}
	g_minishell.envlst = NULL;
}

void	shell_cleaner(void)
{
	ast_cleaner(&g_minishell.ast);
	envlst_cleaner();
	rl_clear_history();
}
