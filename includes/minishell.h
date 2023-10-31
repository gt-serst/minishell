/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/31 16:58:18 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>

# include "../libraries/libft/libft.h"
# include "tokenization.h"
# include "parsing.h"
# include "execution.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_minishell
{
	char			*cmd_line;
	t_token			*tokens;
	t_token			*curr_token;
	t_node			*ast;
	int				exit_s;
	//bool			signint_child;
	int				stdin;
	int				stdout;
	char			**environ;
	t_env			*envlst;
	struct termios	original_term;
}		t_minishell;

void	init_env(char **envp);
void	tokenizer(t_minishell *m);
void	separator_type(char c);
void	identifier_handler(char c);
void	ft_exit_message(char *s);

#endif
