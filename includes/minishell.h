/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/15 11:28:33 by gt-serst         ###   ########.fr       */
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
# include <string.h>
# include <termios.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>

# include "../Libft/libft.h"
# include "tokenization.h"
# include "parsing.h"
# include "expanding.h"
# include "execution.h"
# include "builtins.h"
# include "cleaning.h"
# include "errors.h"

typedef struct s_minishell
{
	t_node			*ast;
	t_token			*tokens;
	t_token			*curr_token;
	t_token_err		token_err;
	t_parsing_err	parsing_err;
	t_expand_err	expand_err;
	t_exec_err		exec_err;
	char			*cmd_line;
	int				err_code;
	char			**environ;
	t_env			*envlst;
	bool			signint_child;
	struct termios	original_term;
}		t_minishell;

t_minishell	g_minishell;

//INIT
void	init_env(char **envp);

//UTILS
void	ft_print_ast(t_node *node);
void	ft_print_expanded_ast(t_node *node);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin_nl(char *s1, char *s2);
char	*ft_strjoin_char(char *s1, char *s2, char c);
void	ft_free_array(char **array);

#endif
