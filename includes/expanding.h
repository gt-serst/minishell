/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:52:16 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/16 14:03:18 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDING_H
# define EXPANDING_H

#include "minishell.h"

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

//	expander
bool	recursive_expander(t_node *node);
bool	expand_args(t_node *node);
char	*handle_dollar(char *str, size_t *i);
char	*handle_dquotes(char *str, size_t *i);
char	*handle_squotes(char *str, size_t *i);
char	*handle_normal_str(char *str, size_t *i);
bool	is_valid_var_char(char c);

// redir
bool	recursive_redir(t_node *node);
bool	input_redir(t_node *node, size_t i);
void	heredoc_redir(t_node *node, size_t i);
bool	output_redir(t_node *node, size_t i);
bool	append_redir(t_node *node, size_t i);

#endif
