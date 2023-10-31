/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:18:19 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/31 08:53:38 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_H
# define TOKENIZATION_H

typedef enum e_token_type
{
	T_IDENTIFIER,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
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
int		separator_recognizer(t_token **t, char	**cmd_line);
int		identifier_handler(t_token **t, char **cmd_line);

//TOKENIZER UTILS
bool	ft_isspace(char	c);
bool	ft_ismetachar(char c);
bool	ft_isquotes(char c);
void	skip_spaces(char **cmd_line);
bool	skip_quotes(char **cmd_line);

//TK UTILS
t_token	*new_tk(void *content, t_token_type type);
void	tkadd_back(t_token **t, t_token *new);
void	tkclear(t_token **token);

#endif
