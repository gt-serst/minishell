/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:srcs/execution/exec_utils.c
/*   Created: 2023/11/09 13:55:30 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/09 13:56:21 by gt-serst         ###   ########.fr       */
========
/*   Created: 2023/10/26 12:03:04 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/02 13:54:07 by mde-plae         ###   ########.fr       */
>>>>>>>> main:srcs/execution/ft_exec.c
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_pipe(int *pipefd)
{
<<<<<<<< HEAD:srcs/execution/exec_utils.c
	close(pipefd[0]);
	close(pipefd[1]);
}
========
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
>>>>>>>> main:srcs/execution/ft_exec.c
