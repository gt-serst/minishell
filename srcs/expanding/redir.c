/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:38:20 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 18:25:41 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_redir(char **arg)
{
	size_t	i;

	i = 2;
	while (arg[i])
	{
		arg[i - 2] = arg[i];
		++i;
	}
	arg[i - 2] = arg[i];
}

static bool	check_redir(t_minishell *m, t_node *node, char **arg)
{
	if (ft_strcmp(*arg, "<") == 0)
		node->data.simple_cmd.fdin = input_redir(*(arg + 1), m);
	else if (ft_strcmp(*arg, "<<") == 0)
		node->data.simple_cmd.fdin = heredoc_redir(m, *(arg + 1));
	else if (ft_strcmp(*arg, ">") == 0)
		node->data.simple_cmd.fdout = output_redir(*(arg + 1), m);
	else if (ft_strcmp(*arg, ">>") == 0)
		node->data.simple_cmd.fdout = append_redir(*(arg + 1), m);
	if (node->data.simple_cmd.fdin < 0 || node->data.simple_cmd.fdout < 0)
		return (false);
	return (true);
}

static bool	open_redir(t_minishell *m, t_node *node)
{
	size_t	i;

	i = 0;
	while (node->data.simple_cmd.expanded_args[i])
	{
		if (arg_is_redir(node->data.simple_cmd.expanded_args[i]))
		{
			if (ft_strlen(node->data.simple_cmd.expanded_args[i + 1]) > 255)
				return (error(E_FILE_LENGTH, NULL,
						node->data.simple_cmd.expanded_args[i + 1], m), false);
			if (!check_redir(m, node, &node->data.simple_cmd.expanded_args[i]))
				return (false);
			remove_redir(&node->data.simple_cmd.expanded_args[i]);
		}
		else
			i++;
	}
	return (true);
}

bool	recursive_redir(t_minishell *m, t_node *node)
{
	if (!node)
		return (false);
	if (node->type == N_CMD)
	{
		if (!open_redir(m, node))
			return (false);
	}
	else
	{
		if (node->data.pipe.left != NULL)
			if (!recursive_redir(m, node->data.pipe.left))
				return (false);
		if (node->data.pipe.right != NULL)
			if (!recursive_redir(m, node->data.pipe.right))
				return (false);
	}
	return (true);
}
