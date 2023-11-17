/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:46 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/17 15:32:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	input_redir(t_node *node, size_t i)
{//input redirection -> modification of stdin
	int	fd;

	if (!node->data.simple_cmd.args || g_minishell.expand_err.type)
		return (false);
	fd = open(node->data.simple_cmd.args[i + 1], O_RDONLY);
	if (fd < 0)
		return (set_expand_err(EE_OPEN), false);
	printf("Input redirection\n");
	node->data.simple_cmd.fdin = fd;
	// dup2(fd, STDIN_FILENO);
	// close(fd);
	return (true);
}

bool	output_redir(t_node *node, size_t i)
{//output redirection -> modification of stdout, if the file doesn't exist it is create, if it exist but there is aleardy content in it, the content will be erased
	int	fd;

	if (!node->data.simple_cmd.args || g_minishell.expand_err.type)
		return (false);
	fd = open(node->data.simple_cmd.args[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (set_expand_err(EE_OPEN), false);
	printf("Output redirection\n");
	node->data.simple_cmd.fdout = fd;
	// dup2(fd, STDOUT_FILENO);
	// close(fd);
	return (true);
}

bool	append_redir(t_node *node, size_t i)
{//output redirection -> modification of stdout, if the file doesn't exist it is create, if it exist but there is aleardy content in it, the new content will be added at the end of the existing content
	int	fd;

	if (!node->data.simple_cmd.args || g_minishell.expand_err.type)
		return (false);
	fd = open(node->data.simple_cmd.args[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		printf("Error\n");
		return (set_expand_err(EE_OPEN), false);
	}
	printf("Append redirection\n");
	node->data.simple_cmd.fdout = fd;
	// dup2(fd, STDOUT_FILENO);
	// close(fd);
	return (true);
}
