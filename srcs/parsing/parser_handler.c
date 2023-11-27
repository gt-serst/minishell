/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:24:59 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 14:58:57 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static bool	get_io_node(t_io_node **io_node, t_token *curr_token)
// {
// 	t_io_node	*new_io_node;

// 	new_io_node = new_io_nd(get_io_nd_type(curr_token->type));
// malloc in new_io_node
// 	if (!new_io_node)
// 		return (false);
// 	printf("Io node type: %d\n", new_io_node->type);
// 	io_lstadd_back(io_node, new_io_node);
// 	return (true);
// }

static int	arglen(t_token **curr_token)
{
	t_token	*tmp;
	int		res;

	tmp = *curr_token;
	res = 0;
	while (tmp && (tmp->type == T_IDENTIFIER
			|| is_redir(tmp->type)))
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

static bool	token_into_args(t_node *simple_cmd,
	t_token **curr_token, t_minishell *m)
{
	int	i;

	i = -1;
	simple_cmd->data.simple_cmd.args
		= malloc(sizeof(char *) * (arglen(curr_token) + 1));
	if (!simple_cmd->data.simple_cmd.args)
		return (error(E_MEM, NULL, NULL, m), false);
	ft_bzero(simple_cmd->data.simple_cmd.args, sizeof(char *));
	while (*curr_token && ((*curr_token)->type == T_IDENTIFIER
			|| is_redir((*curr_token)->type)))
	{
		if ((*curr_token)->type == T_HEREDOC)
			simple_cmd->data.simple_cmd.heredoc = true;
		simple_cmd->data.simple_cmd.args[++i] = ft_strdup((*curr_token)->value);
		get_next_token(curr_token);
	}
	simple_cmd->data.simple_cmd.args[++i] = NULL;
	return (true);
}
/*
		if (is_redir(g_minishell.curr_token->type))
		{
			if (!get_io_node(io_node, curr_token))
				return (false);
		}
*/

t_node	*get_simple_cmd(t_token **curr_token, t_minishell *m)
{
	t_node	*simple_cmd;

	if (!*curr_token || is_pipe(*curr_token))
		return (NULL);
	simple_cmd = new_nd(N_CMD);
	if (!simple_cmd)
		return (error(E_MEM, NULL, NULL, m), NULL);
	while (*curr_token && ((*curr_token)->type == T_IDENTIFIER
			|| is_redir((*curr_token)->type)))
	{
		if (is_redir((*curr_token)->type) && ((*curr_token)->next == NULL))
		{
			free((*curr_token)->value);
			(*curr_token)->value = ft_strdup("new_line");
			return (NULL);
		}
		simple_cmd->data.simple_cmd.fdin = STDIN_FILENO;
		simple_cmd->data.simple_cmd.fdout = STDOUT_FILENO;
		if (!token_into_args(simple_cmd, curr_token, m))
			return (error(E_MEM, NULL, NULL, m), NULL);
	}
	return (simple_cmd);
}
// get the cmd and the cmd args of the simple
// cmd then create a tree node
