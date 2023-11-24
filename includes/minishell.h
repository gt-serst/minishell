/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 15:24:04 by mde-plae         ###   ########.fr       */
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
# include "builtins.h"
# include "execution.h"
# include "cleaning.h"

int	g_signint;

typedef enum e_err_type
{
	E_QUOTES,
	E_FILE,
	E_NO_SUCH_FILE,
	E_TOO_MANY_ARGS,
	E_SYNTAX,
	E_MEM = 12,
	E_CMD_NOT_FOUND = 127,
	E_NUM_MANDATORY = 255,
	E_UNEXP_TOK = 258
}		t_err_type;

typedef struct s_err
{
	t_err_type	type;
	char		*str;
}		t_err;

//	init
void	init_env(t_minishell *m, char **envp);

//	error
void	error(t_err_type type, char *token, char *cmd);
void	num_mandatory_err_message(char *cmd);
void	cmd_err_message(char *cmd);
void	unexp_tok_err_message(char *token);
void	file_err_message(char *file);
void	quotes_err_message(char *s);
void	ft_exit_message(char *str);
void	ft_set_exit_val(int exit_value);
int		*ft_get_exit_val(void);

//	utils
void	ft_print_token(t_token *token);
void	ft_print_ast(t_node *node);
void	ft_print_expanded_ast(t_node *node);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin_nl(char *s1, char *s2);
char	*ft_strjoin_char(char *s1, char *s2, char c);
void	ft_free_array(char **array);
void	read_from_fd(t_node *node);

// signals
void	init_signals(t_minishell *m);
void	sigquit_handler(int num);

#endif
