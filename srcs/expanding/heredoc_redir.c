/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:01:08 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/08 16:32:45 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_redir(t_node *node, size_t i)
{//heredoc is a write input, when the user types a sequence of predefined characters (EOF) then the write input closes, a sigint signal can also interrupt the write input
	char	*cmd_line;
	char	*buf;

	if (!node->data.simple_cmd.args || g_minishell.expand_err.type)
		return ;
	buf = NULL;
	while (1)
	{
		cmd_line = readline("> ");
		if (!cmd_line)
			break ;
		if (ft_strcmp(node->data.simple_cmd.args[i + 1], cmd_line) == 0)
		{
			break ;
		}
		if (buf)
			buf = ft_strjoin_nl(buf, cmd_line);
		else
			buf = ft_strdup(cmd_line);
		if (!buf)
			break ;
	}
	ft_putstr_fd(buf, node->data.simple_cmd.fdout);
	if (buf)
		ft_putstr_fd("\n", node->data.simple_cmd.fdout);
}
