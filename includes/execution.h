/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:14:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/14 12:05:39 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef enum e_exec_err_type
{
	EXE_ARG,
	EXE_CMD_NOT_FOUND,
	EXE_NO_SUCH_FILE,
	EXE_PERM_DENIED,
	EXE_TOO_MANY_ARGS,
	EXE_NUM_MANDATORY
}	t_exec_err_type;

typedef struct s_exec_err
{
	t_exec_err_type type;
	char			*str;
}	t_exec_err;

typedef enum e_ast_direction
{
	D_LEFT,
	D_RIGHT
}	t_ast_direction;

//	execution
void	exec_ast(t_node *node);
int	exec_pipeline(t_node *node);
int	exec_simple_cmd(t_node *node);
int		exec_builtins(char **args);
bool	is_builtin(char *arg);
char	*path_to_cmd(char *cmd);

//	utils
void	close_pipe(int *pipefd);

#endif
