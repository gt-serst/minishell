/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/03 12:29:26 by gt-serst         ###   ########.fr       */
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
#include "execution.h"

typedef struct s_minishell
{
	t_node			*ast;
	t_token			*tokens;
	t_token			*curr_token;
	t_parsing_err	parsing_err;
	t_expand_err	expand_err;
	char			*cmd_line;
	int				err_code;
}		t_minishell;

extern t_minishell	g_minishell;

//INIT
void	init_env(char **envp);

//ERR
void	ft_exit_message(char *s);

//TOKENIZATION ERR
void	quotes_err_message(char c);

//PARSING ERR
void		set_parsing_err(t_parsing_err_type type);
t_node		*parsing_err_handler(void);
void	set_expand_err(t_expand_err_type type);

//UTILS
void	ft_print_ast(t_node *node);

#endif
