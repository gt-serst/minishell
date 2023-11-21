/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/21 14:31:02 by gt-serst         ###   ########.fr       */
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

typedef struct s_io
{
	int	input;
	int	output;
}		t_io;

typedef struct s_prompt
{
	char	**env;
	char	*cmd_line;
}		t_prompt;

typedef struct s_minishell
{
	t_token	*token;
	t_node	*ast;
	int		err_code;
}		t_minishell;

//INIT
void	init_env(char **envp);

//ERRORS
void	error(int err, char *token, char *cmd);

//UTILS
void	ft_print_ast(t_node *node);
void	ft_print_expanded_ast(t_node *node);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin_nl(char *s1, char *s2);
char	*ft_strjoin_char(char *s1, char *s2, char c);
void	ft_free_array(char **array);
void	read_from_fd(t_node *node);

#endif
