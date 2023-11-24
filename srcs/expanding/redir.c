/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:38:20 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 11:42:43 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_redir(t_node *node)
{
	size_t	i;

	i = 0;
	while (node->data.simple_cmd.args[i])
	{
		if (ft_strcmp(node->data.simple_cmd.args[i], "<") == 0
			|| ft_strcmp(node->data.simple_cmd.args[i], "<<") == 0
			|| ft_strcmp(node->data.simple_cmd.args[i], ">") == 0
			|| ft_strcmp(node->data.simple_cmd.args[i], ">>") == 0)
		{
			node->data.simple_cmd.expanded_args[i] = NULL;
			node->data.simple_cmd.expanded_args[i + 1] = NULL;
		}
		i++;
	}
}

bool	launch_redir(t_node *node)
{
	size_t	i;

	i = 0;
	while (node->data.simple_cmd.args[i])
	{
		if (ft_strcmp(node->data.simple_cmd.args[i], "<") == 0)
			node->data.simple_cmd.fdin = input_redir(node, i);
		else if (ft_strcmp(node->data.simple_cmd.args[i], "<<") == 0)
			node->data.simple_cmd.fdin = heredoc_redir(node, i);
		else if (ft_strcmp(node->data.simple_cmd.args[i], ">") == 0)
			node->data.simple_cmd.fdout = output_redir(node, i);
		else if (ft_strcmp(node->data.simple_cmd.args[i], ">>") == 0)
			node->data.simple_cmd.fdout = append_redir(node, i);
		if (node->data.simple_cmd.fdin < 0 || node->data.simple_cmd.fdout < 0)
			return (false);
		i++;
	}
	remove_redir(node);
	return (true);
}

bool	recursive_redir(t_node *node)
{
	if (!node)
		return (false);
	if (node->type == N_CMD)
	{
		if (!launch_redir(node))
			return (false);
	}
	else
	{
		if (node->data.pipe.left != NULL)
			if (!recursive_redir(node->data.pipe.left))
				return (false);
		if (node->data.pipe.right != NULL)
			if (!recursive_redir(node->data.pipe.right))
				return (false);
	}
	return (true);
}
