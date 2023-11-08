/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:14:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/08 12:25:13 by mde-plae         ###   ########.fr       */
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
void	ft_exec(void);
void	ft_ast_init(t_node *node);
void	ft_leaf_init(t_node *node);
void	exec_ast(t_node *node);

//	expander
char	**ft_expand_args(char *str);


#endif
