/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:52:16 by gt-serst          #+#    #+#             */
/*   Updated: 2023/12/28 19:35:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDING_H
# define EXPANDING_H

# include "minishell.h"

//	expander
bool	recursive_expander(t_minishell *m, t_node *node);
bool	expand_args(t_minishell *m, t_node *node);
char	*handle_dollar(t_minishell *m, char *str, size_t *i);
char	*handle_dquotes(t_minishell *m, char *str, size_t *i);
char	*handle_squotes(char *str, size_t *i);
char	*handle_normal_str(char *str, size_t *i);
bool	is_valid_var_char(char c);

//	redir
bool	recursive_redir(t_minishell *m, t_node *node);
int		input_redir(char *args, t_minishell *m);
int		heredoc_redir(t_minishell *m, char *delimiter);
int		output_redir(char *args, t_minishell *m);
int		append_redir(char *args, t_minishell *m);

//	utils
bool	arg_is_redir(char *arg);
bool	is_delimiter(char *delimiter, char *line);
char	*heredoc_handle_normal_str(char *str, size_t *i);
char	*heredoc_expander(t_minishell *m, char *str);

#endif
