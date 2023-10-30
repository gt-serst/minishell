/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/30 15:48:34 by gt-serst         ###   ########.fr       */
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

//UTILS
void	ft_print_token(t_token **t);
void	ft_print_token_reverse(t_token **t);
void	ft_print_left_side(t_node *node);
void	ft_print_right_side(t_node *node);
char	*join_with_char(char *s1, char *s2, char c);
void	ft_print_io_list(t_io_node **io_lst);

#endif
