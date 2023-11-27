/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:14:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/27 14:02:38 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef enum e_ast_direction
{
	D_LEFT,
	D_RIGHT
}	t_ast_direction;

//	execution
int		exec_ast(t_minishell *m, t_node *node);
int		exec_node(t_minishell *m, t_node *node, bool piped);
int		exec_pipeline(t_minishell *m, t_node *node);
int		exec_simple_cmd(t_minishell *m, t_node *node, bool piped);
int		exec_builtins(t_minishell *m, char **args, bool piped);
bool	is_builtin(char *arg);
char	*path_to_cmd(t_env *envlst, char *cmd, t_minishell *m);

//	utils
int		get_exit_status(int status);
void	close_pipe(int *pipefd);
void	close_io(t_minishell *m, bool piped);

#endif
