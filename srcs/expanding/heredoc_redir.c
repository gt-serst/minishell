/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:01:08 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/07 09:45:08 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_heredoc_sigint_handler(int signum)
{//catch the sigint signal and exit
	(void)signum;
	ast_cleaner(&g_minishell.ast);
	exit(SIGINT);
}

bool	is_end_of_file(char *end_of_file, char *cmd_line)
{//check if the EOF writing by the user is correct, remove pairs of quotes before compare, if a pair of quotes is missing the heredoc cannot quit by writing the EOF
	char	*eof_trim;

	//printf("Eof %s\n", end_of_file);
	eof_trim = ft_strtrim(end_of_file, "\"");
	eof_trim = ft_strtrim(eof_trim, "\'");
	//printf("Eof trim %s\n", eof_trim);
	if (ft_strcmp(eof_trim, cmd_line) == 0)
		return (true);
	else
		return (false);
}

void	heredoc_redir(t_node *node)
{//heredoc is a write input, when the user types a sequence of predefined characters (EOF) then the write input closes, a sigint signal can also interrupt the write input
	char	*cmd_line;
	char	*quotes;

	if (!node->data.simple_cmd.args || g_minishell.expand_err.type)
		return ;
	signal(SIGINT, ft_heredoc_sigint_handler);
	quotes = node->data.simple_cmd.args[2];
	while (*quotes && *quotes == '"' && *quotes == '\'')
		quotes++;
	while (1)
	{
		cmd_line = readline("> ");
		if (!cmd_line)
			break ;
		if (is_end_of_file(node->data.simple_cmd.args[2], cmd_line))
			break ;
		else
		{
			ft_putstr_fd(cmd_line, node->data.simple_cmd.fdout);
			ft_putstr_fd("\n", node->data.simple_cmd.fdout);
		}
	}
	ast_cleaner(&node);
	exit (0);
}
