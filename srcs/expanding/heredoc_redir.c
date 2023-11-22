/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:01:08 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/22 16:19:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void multiple_heredoc_redir(t_node *node, size_t i)
{
	char	*cmd_line;
	char	*buf;

	buf = NULL;
	while (1)
	{
		cmd_line = readline("> ");
		if (!cmd_line)
			break ;
		if (ft_strcmp(node->data.simple_cmd.expanded_args[i + 1], cmd_line) == 0)
			break ;
		if (!buf)
			buf = ft_strdup(cmd_line);
		else
			buf = ft_strjoin_nl(buf, cmd_line);
		if (!buf)
			break ;
	}
	if (buf)
		free(buf);
}

static void	single_heredoc_redir(t_node *node)
{
	char	*cmd_line;
	char	*buf;

	buf = NULL;
	while (1)
	{
		cmd_line = readline("> ");
		if (!cmd_line)
			break ;
		if (ft_strcmp(node->data.simple_cmd.expanded_args[2], cmd_line) == 0)
			break ;
		if (!buf)
			buf = ft_strdup(cmd_line);
		else
			buf = ft_strjoin_nl(buf, cmd_line);
		if (!buf)
			break ;
	}
	ft_putstr_fd(buf, node->data.simple_cmd.fdout);
	if (buf)
	{
		ft_putstr_fd("\n", node->data.simple_cmd.fdout);
		free(buf);
	}
}

int	heredoc_redir(t_node *node, size_t i)
{//heredoc is a write input, when the user types a sequence of predefined characters (EOF) then the write input closes, a sigint signal can also interrupt the write input
	size_t	j;
	size_t	count;

	if (!node->data.simple_cmd.args)
		return (-1);
	count = 0;
	j = i + 1;
	while (node->data.simple_cmd.args[j])
	{
		if(ft_strcmp(node->data.simple_cmd.args[j], "<<") == 0)
			count++;
		j++;
	}
	if (count > 0)
		multiple_heredoc_redir(node, i);
	else
		single_heredoc_redir(node);
	return (0);
}
