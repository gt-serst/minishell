/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:18:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/20 22:11:35 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_H
# define TOKENIZATION_H

typedef enum e_token_err_type
{
	TE_MEM = 1,
	TE_SYNTAX,
	TE_QUOTES,
	TE_UNEXP_TOK
}	t_token_err_type;

typedef struct s_token_err
{
	t_token_err_type	type;
	char				*str;
}	t_token_err;

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

/*
typedef enum e_token_err
{
	EE_MEM,
	EE_SYNTAX,
	EE_OPEN
}	t_token_err_type;

typedef struct s_token_err
{
	t_token_err_type	type;
	char				*str;
}	t_token_err;
*/

//TOKENIZATION
t_token	*tokenizer(void);
bool	unexpected_token(char c);
t_token	*separator_handler(char	**cmd_line);
t_token	*identifier_handler(char **cmd_line);

//TOKENIZER UTILS
bool	ft_isspace(char	c);
bool	ft_ismetachar(char c);
bool	ft_isquotes(char c);
void	skip_spaces(char **cmd_line);
bool	skip_quotes(char *cmd_line, size_t *i);

//TK UTILS
t_token	*new_tk(void *content, t_token_type type);
void	tk_lstadd_back(t_token **t, t_token *elem);
void	tkclear(t_token **token);

#endif
