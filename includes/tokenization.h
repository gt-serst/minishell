/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:18:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/02 12:38:29 by gt-serst         ###   ########.fr       */
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

//TOKENIZATION
t_token	*tokenizer(void);
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
void	tkadd_back(t_token **t, t_token *elem);
void	tkclear(t_token **token);

#endif
