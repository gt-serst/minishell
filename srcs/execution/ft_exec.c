/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:03:04 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/02 13:54:07 by mde-plae         ###   ########.fr       */
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

int	exec_pipe(t_node ast)
{
	
}

int	exec_node(t_node *ast)
{
	if(ast->N_PIPE)
		return (exec_pipe(ast));
}