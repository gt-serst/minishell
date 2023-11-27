/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:01:08 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 14:15:13 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	heredoc_sigint_handler(int signum)
{
	(void)signum;
	//shell_cleaner();
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static bool	is_delimiter(char *delimiter, char *line)
{
	if (!line || ft_strcmp(line, "") == 0)
		return (false);
	while (*line)
	{
		if (*delimiter == '"' || *delimiter == '\'')
		{
			delimiter++;
			continue ;
		}
		else if (*line == *delimiter)
		{
			line++;
			delimiter++;
		}
		else
			return (false);
	}
	return (true);
}

static char	*append_input(char **cmd_line, char *new_line)
{
	if (!*cmd_line)
		*cmd_line = ft_strdup(new_line);
	else
		*cmd_line = ft_strjoin_nl(*cmd_line, new_line);
	return (*cmd_line);
}

static void	init_heredoc(int *fd, char **new_line, char **cmd_line)
{
	*new_line = NULL;
	*cmd_line = NULL;
	if (pipe(fd) == -1)
		return ;
}

static char	*get_heredoc_input(int *fd, char *delimiter)
{
	char	*new_line;
	char	*cmd_line;

	init_heredoc(fd, &new_line, &cmd_line);
	signal(SIGINT, heredoc_sigint_handler);
	while (1)
	{
		new_line = readline("> ");
		if (!new_line)
			break ;
		if (is_delimiter(delimiter, new_line) == true)
			break ;
		append_input(&cmd_line, new_line);
	}
	free(new_line);
	return (cmd_line);
}

int	heredoc_redir(t_minishell *m, char *delimiter)
{
	char	*input;
	int		fd[2];

	input = get_heredoc_input(fd, delimiter);
	if (!input)
		return (0);
	input = heredoc_expander(m, input);
	/*if (multiple_heredoc)
	{
		close(fd[STDOUT_FILENO]);
		free(input);
		return (fd[0]);
	}*/
	ft_putstr_fd(input, fd[STDOUT_FILENO]);
	ft_putstr_fd("\n", fd[STDOUT_FILENO]);
	free(input);
	close(fd[STDOUT_FILENO]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (1);
}
//heredoc is a write input, when the user types a sequence
// of predefined characters (EOF) then the write input closes,
// a sigint signal can also interrupt the write input
