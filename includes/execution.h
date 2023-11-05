/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:14:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/05 19:16:11 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef enum e_expand_err
{
	EE_MEM,
	EE_SYNTAX,
	EE_OPEN
}	t_expand_err_type;

typedef struct s_expand_err
{
	t_expand_err_type	type;
	char				*str;
}	t_expand_err;

//	execution
void	exec_ast(t_node *node);

//	expander
char	**expand_args(char *str);
bool	recursive_redir(t_node *node);
bool	input_redir(t_node *node);
void	heredoc_redir(t_node *node);
bool	output_redir(t_node *node);
bool	append_redir(t_node *node);

#endif
