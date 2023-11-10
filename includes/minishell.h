/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/10 15:44:52 by mde-plae         ###   ########.fr       */
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
# include "expanding.h"
# include "execution.h"
# include "builtins.h"


t_minishell	g_minishell;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct
{
	int			err_code;
	const char	*err_msg;
} t_err;



typedef struct s_minishell
{
	t_node			*ast;
	t_token			*tokens;
	t_token			*curr_token;
	//t_token_err		token_err;
	t_parsing_err	parsing_err;
	t_expand_err	expand_err;
	char			*cmd_line;
	int				err_code;
	char			**environ;
	t_env			*envlst;
	int				err_code;
	bool			signint_child;
}		t_minishell;

//INIT
void	init_env(char **envp);

//ERR
void	ft_exit_message(char *s);

//TOKENIZATION ERR
void	quotes_err_message(char c);

//PARSING ERR
void		set_parsing_err(t_parsing_err_type type);
void		parsing_err_handler(void);
void		set_expand_err(t_expand_err_type type);
void		expanding_err_handler(void);


//UTILS
void	ft_print_ast(t_node *node);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin_nl(char *s1, char *s2);

#endif
