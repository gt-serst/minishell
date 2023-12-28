/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:12:28 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/28 19:34:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shell_cleaner(t_minishell *m)
{
	ast_cleaner(&m->ast);
}

void	shell_shutdown(t_minishell *m)
{
	shell_cleaner(m);
	garbage_collector(NULL, true);
	clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &m->original_term);
}
