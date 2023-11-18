/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:38:20 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/18 22:51:13 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void remove_redir(t_node *node)
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
		//printf("%s\n", node->data.simple_cmd.expanded_args[i]);
		i++;
	}
}

bool	launch_redir(t_node *node)
{
	size_t	i;

	if (g_minishell.expand_err.type)
		return (false);
	i = 0;
	while (node->data.simple_cmd.args[i])
	{
		if(ft_strcmp(node->data.simple_cmd.args[i], "<") == 0)
			input_redir(node, i);
		else if(ft_strcmp(node->data.simple_cmd.args[i], "<<") == 0)
			heredoc_redir(node, i);
		else if(ft_strcmp(node->data.simple_cmd.args[i], ">") == 0)
			output_redir(node, i);
		else if(ft_strcmp(node->data.simple_cmd.args[i], ">>") == 0)
			append_redir(node, i);
		i++;
	}
	if (g_minishell.expand_err.type)
		return (false);
	remove_redir(node);
	return (true);
}

bool	recursive_redir(t_node *node)
{
	if (!node || g_minishell.expand_err.type)
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
