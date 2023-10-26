/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:24:59 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/26 10:52:10 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_io_list(t_io_node **io_list)
{
	t_io_node		*tmp_io_node;
	t_token_type	redir_type;

	while (is_redir())
	{
		redir_type = g_minishell.curr_token->type;
		get_next_token();
		tmp_io_node = new_io_node(redir_type, g_minishell.curr_token->value);
		if (!tmp_io_node)
			return (false);
		append_io_node(io_list, tmp_io_node);
		get_next_token();
	}
	return (true);
}

bool	join_args(char **args)
{
	while (g_minishell.curr_token->type == T_IDENTIFIER)
	{
		*args = ft_strjoin(&args, g_minishell.curr_token->value); //allocation in strjoin
		if (*args)
			return (false);
		get_next_token();
	}
	return (true);
}

t_node	*get_simple_cmd(void)
{// get the cmd and the cmd args of the simple cmd then create a tree node
	t_node	*new;

	new = new_node(T_IDENTIFIER);
	while (g_minishell.curr_token->type == T_IDENTIFIER
		|| is_redir(g_minishell.curr_token->type))
	{
		if (g_minishell.curr_token->type == T_IDENTIFIER)
			join_args(new->args);
		else if (is_redir(g_minishell.curr_token->type))
			get_io_list(new->io_list);
	}
	return (new);
}
