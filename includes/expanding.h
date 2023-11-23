/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:52:16 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 10:24:36 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDING_H
# define EXPANDING_H

#include "minishell.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_minishell
{
	int					input;
	int					output;
	char				*cmd_line;
	t_token				*token;
	t_node				*ast;
	t_env				*envlst;
	char				**env;
	int					err_code;
	struct termios		original_term;
}		t_minishell;

//	expander
bool	recursive_expander(t_minishell *m, t_node *node);
bool	expand_args(t_minishell *m, t_node *node);
char	*handle_dollar(t_minishell *m, char *str, size_t *i);
char	*handle_dquotes(t_minishell *m, char *str, size_t *i);
char	*handle_squotes(char *str, size_t *i);
char	*handle_normal_str(char *str, size_t *i);
bool	is_valid_var_char(char c);

//	redir
bool	recursive_redir(t_node *node);
int		input_redir(t_node *node, size_t i);
int		heredoc_redir(t_node *node, size_t i);
int		output_redir(t_node *node, size_t i);
int		append_redir(t_node *node, size_t i);

#endif
