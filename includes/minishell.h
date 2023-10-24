/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 14:44:56 by gt-serst         ###   ########.fr       */
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
	char	*cmd_line;
}		t_minishell;

//INIT
void	init_env(char **envp);

//EXIT
void	ft_exit_message(char *s);

//UTILS
void	ft_printlst(t_minishell *m);
void	ft_printlst_reverse(t_minishell *m);

//TOKENIZATION
void	tokenizer(t_minishell *m);
void	separator_type(t_minishell *m, char	*cmd_line);
void	identifier_handler(t_minishell *m, char *cmd_line);
bool	ft_isspace(char	c);
t_token	*new_tk(void *content, t_token_type type);
void	tkadd_back(t_token **t, t_token *new);


#endif
