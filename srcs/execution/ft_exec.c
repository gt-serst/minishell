/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:03:04 by mde-plae          #+#    #+#             */
/*   Updated: 2023/10/31 16:52:45 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exec(void)
{
	signal(SIGQUIT, ft_sigquit_handler);
	ft_ast_init(t_minishell.ast);
	tcsetattr(STDIN_FILENO, TCSANOW, &t_minishell.original_term);
	//exec_node
}