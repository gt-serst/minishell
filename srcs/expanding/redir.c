/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:38:20 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/08 16:27:34 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	launch_redir(t_node *node)
{
	size_t	i;
	bool	mheredoc;

	if (g_minishell.expand_err.type)
		return (false);
	i = 0;
	mheredoc = false;
	while (node->data.simple_cmd.args[i])
	{
		if(ft_strcmp(node->data.simple_cmd.args[i], "<") == 0)
			input_redir(node);
		else if(ft_strcmp(node->data.simple_cmd.args[i], "<<") == 0)
			heredoc_redir(node, i);
		else if(ft_strcmp(node->data.simple_cmd.args[i], ">") == 0)
			output_redir(node);
		else if(ft_strcmp(node->data.simple_cmd.args[i], ">>") == 0)
			append_redir(node);
		i++;
	}
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
