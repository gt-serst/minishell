/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:52:16 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 14:00:02 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDING_H
# define EXPANDING_H

# include "minishell.h"

/*
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
*/

//	expander
bool	recursive_expander(t_minishell *m, t_node *node);
bool	expand_args(t_minishell *m, t_node *node);
char	*heredoc_expander(t_minishell *m, char *str);
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

#endif
