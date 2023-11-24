/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:46 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 11:42:12 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	input_redir(t_node *node, size_t i)
{
	int	fd;

	if (!node->data.simple_cmd.args)
		return (-1);
	fd = open(node->data.simple_cmd.args[i + 1], O_RDONLY);
	if (fd < 0)
		error(E_FILE, NULL, node->data.simple_cmd.args[i + 1]);
	return (fd);
}
//input redirection -> modification of stdin

int	output_redir(t_node *node, size_t i)
{
	int	fd;

	if (!node->data.simple_cmd.args)
		return (-1);
	fd = open(node->data.simple_cmd.args[i + 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		error(E_FILE, NULL, node->data.simple_cmd.args[i + 1]);
	return (fd);
}
//output redirection -> modification of stdout,
// if the file doesn't exist it is create,
// if it exist but there is aleardy content in it, the content will be erased

int	append_redir(t_node *node, size_t i)
{
	int	fd;

	if (!node->data.simple_cmd.args)
		return (-1);
	fd = open(node->data.simple_cmd.args[i + 1],
			O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		error(E_FILE, NULL, node->data.simple_cmd.args[i + 1]);
	return (fd);
}
//output redirection -> modification of stdout,
// if the file doesn't exist it is create,
// if it exist but there is aleardy content in it,
// the new content will be added at the end of the existing content
