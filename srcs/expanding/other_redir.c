/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:46 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 14:39:56 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	input_redir(char *args)
{
	int	fd;

	if (!args)
		return (-1);
	fd = open(args, O_RDONLY);
	if (fd < 0)
		error(E_FILE, NULL, args);
	return (fd);
}
//input redirection -> modification of stdin

int	output_redir(char *args)
{
	int	fd;

	if (!args)
		return (-1);
	fd = open(args, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		error(E_FILE, NULL, args);
	return (fd);
}
//output redirection -> modification of stdout,
// if the file doesn't exist it is create,
// if it exist but there is aleardy content in it, the content will be erased

int	append_redir(char *args)
{
	int	fd;

	if (!args)
		return (-1);
	fd = open(args, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
		error(E_FILE, NULL, args);
	return (fd);
}
//output redirection -> modification of stdout,
// if the file doesn't exist it is create,
// if it exist but there is aleardy content in it,
// the new content will be added at the end of the existing content
