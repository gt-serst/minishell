/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:12:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 14:09:42 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	envlst_cleaner(t_env **envlst)
{
	t_env	*current;
	t_env	*tmp;

	if (!envlst)
		return ;
	current = *envlst;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	*envlst = NULL;
}

void	shell_cleaner(t_minishell *m)
{
	ast_cleaner(&m->ast);
	tcsetattr(STDIN_FILENO, TCSANOW, &m->original_term);
}

void	shell_shutdown(t_minishell *m)
{
	ast_cleaner(&m->ast);
	envlst_cleaner(&m->envlst);
	clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &m->original_term);
}
