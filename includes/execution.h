/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:14:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/09 15:49:10 by gt-serst         ###   ########.fr       */
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
void	exec_ast(t_node *node);
void	exec_pipeline(t_node *node);

//	utils
void	close_pipe(int *pipefd);

#endif
