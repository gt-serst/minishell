/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/25 17:03:55 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../libraries/libft/libft.h"
#include "tokenization.h"
#include "parsing.h"

typedef struct s_minishell
{
	t_node	*ast;
	t_token	*tokens;
	t_token	*curr_token;
	char	*cmd_line;
}		t_minishell;

extern t_minishell	g_minishell;

//INIT
void	init_env(char **envp);

//ERR
void	ft_exit_message(char *s);
void	quotes_err_message(char c);

//UTILS
void	ft_printlst(t_token **t);
void	ft_printlst_reverse(t_token **t);

//TOKENIZATION
t_token	*tokenizer(void);
int	separator_recognizer(t_token **t, char	**cmd_line);
int	identifier_handler(t_token **t, char **cmd_line);

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
