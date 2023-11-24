/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:18:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 17:36:55 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_H
# define TOKENIZATION_H

typedef enum e_token_type
{
	T_IDENTIFIER,
	T_INPUT,
	T_OUTPUT,
	T_HEREDOC,
	T_APPEND,
	T_PIPE,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef enum e_node_type
{
	N_PIPE,
	N_CMD
}	t_node_type;

typedef enum e_io_node_type
{
	IO_INPUT,
	IO_OUTPUT,
	IO_HEREOC,
	IO_APPEND
}	t_io_node_type;

typedef struct s_io_node
{
	t_io_node_type		type;
	struct s_io_node	*next;
}		t_io_node;

typedef struct s_simple_cmd
{
	char	**args;
	char	**expanded_args;
	int		fdin;
	int		fdout;
}	t_simple_cmd;

typedef struct s_pipe
{
	struct s_node		*left;
	struct s_node		*right;
}	t_pipe;

typedef struct s_node_data
{
	t_simple_cmd	simple_cmd;
	t_pipe			pipe;
}	t_node_data;

typedef struct s_node
{
	t_node_type	type;
	t_node_data	data;
}	t_node;

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

//	tokenization
t_token	*tokenizer(t_minishell *m);
bool	unexpected_token(char c);
t_token	*separator_handler(char	**cmd_line);
t_token	*identifier_handler(char **cmd_line);

//	tokenizer utils
bool	ft_isspace(char	c);
bool	ft_ismetachar(char c);
bool	ft_isquotes(char c);
void	skip_spaces(char **cmd_line);
bool	skip_quotes(char *cmd_line, size_t *i);

//	token utils
t_token	*new_tk(void *content, t_token_type type);
void	tk_lstadd_back(t_token **token, t_token *elem);
void	tkclear(t_token **token);

#endif
