/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:24:59 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/26 15:03:34 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	get_io_list(t_io_node **io_list)
{
	t_io_node		*tmp_io_node;
	t_io_type	redir_type;

	redir_type = get_io_type(g_minishell.curr_token->type);
	while (is_redir(g_minishell.curr_token->type))
	{
		redir_type = get_io_type(g_minishell.curr_token->type);
		tmp_io_node = new_io_node(redir_type, g_minishell.curr_token->value);
		if (!tmp_io_node)
			return (set_parsing_err(E_MEM), false);
		addback_io_node(io_list, tmp_io_node);
		get_next_token();
	}
	return (true);
}

static bool	join_args(char **args)
{
	while (g_minishell.curr_token->type == T_IDENTIFIER)
	{
		*args = ft_strjoin(*args, g_minishell.curr_token->value); //allocation in strjoin
		if (*args)
			return (set_parsing_err(E_MEM), false);
		get_next_token();
	}
	return (true);
}

t_node	*get_simple_cmd(void)
{// get the cmd and the cmd args of the simple cmd then create a tree node
	t_node	*new;

	new = new_node(N_CMD);
	if (!new)
		return (set_parsing_err(E_MEM), NULL);
	while (g_minishell.curr_token->type == T_IDENTIFIER
		|| is_redir(g_minishell.curr_token->type))
	{
		if (g_minishell.curr_token->type == T_IDENTIFIER)
		{
			if (!join_args(&(new->args)))
				return (NULL);
		}
		else if (is_redir(g_minishell.curr_token->type))
		{
			if (!get_io_list(&(new->io_list)))
				return (NULL);
		}
	}
	return (new);
}
