/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:12:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 14:00:21 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	envlst_cleaner(t_env **envlst)
{
	t_env	*current;
	t_env	*next;

	if (!envlst)
		return ;
	current = *envlst;
	while (current != NULL)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		current = next;
		free(current);
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
