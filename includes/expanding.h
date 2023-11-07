/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:52:16 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/07 14:04:48 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef EXPANDING_H
# define EXPANDING_H

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
bool	input_redir(t_node *node);
void	heredoc_redir(t_node *node);
bool	output_redir(t_node *node);
bool	append_redir(t_node *node);

#endif
