/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:24:59 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 11:31:27 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
static bool	get_io_node(t_io_node **io_node, t_token *curr_token)
{
	t_io_node	*new_io_node;

	new_io_node = new_io_nd(get_io_nd_type(curr_token->type)); //malloc in new_io_node
	if (!new_io_node)
		return (false);
	printf("Io node type: %d\n", new_io_node->type);
	io_lstadd_back(io_node, new_io_node);
	return (true);
}
*/

static int	arglen(t_token *curr_token)
{
	t_token	*token;
	int		res;

	token = curr_token;
	res = 0;
	while (token && (token->type == T_IDENTIFIER
			|| is_redir(token->type)))
	{
		res++;
		token = token->next;
	}
	return (res);
}

static bool	token_into_args(t_node *simple_cmd, t_token **curr_token)
{
	int	i;

	i = -1;
	simple_cmd->data.simple_cmd.args = malloc(sizeof(char *) * (arglen(*curr_token) + 1));
	if (!simple_cmd->data.simple_cmd.args)
		return (error(E_MEM, NULL, NULL), false);
	ft_bzero(simple_cmd->data.simple_cmd.args, sizeof(char *));
	while (*curr_token && ((*curr_token)->type == T_IDENTIFIER
		|| is_redir((*curr_token)->type)))
	{
		simple_cmd->data.simple_cmd.args[++i] = ft_strdup((*curr_token)->value);
/*
		if (is_redir(g_minishell.curr_token->type))
		{
			if (!get_io_node(io_node, curr_token))
				return (false);
		}
*/
		get_next_token(curr_token);
	}
	simple_cmd->data.simple_cmd.args[++i] = NULL;
	return (true);
}

t_node	*get_simple_cmd(t_token **curr_token)
{// get the cmd and the cmd args of the simple cmd then create a tree node
	t_node	*simple_cmd;

	if (!*curr_token)
		return (NULL);
	simple_cmd = new_nd(N_CMD);
	if (!simple_cmd)
		return (error(E_MEM, NULL, NULL), NULL);
	while (*curr_token && ((*curr_token)->type == T_IDENTIFIER
		|| is_redir((*curr_token)->type)))
	{
		simple_cmd->data.simple_cmd.fdin = STDIN_FILENO;
		simple_cmd->data.simple_cmd.fdout = STDOUT_FILENO;
		if (!token_into_args(simple_cmd, curr_token))
			return (error(E_MEM, NULL, NULL), NULL);
		printf("%s\n", simple_cmd->data.simple_cmd.args[0]);
	}
	return (simple_cmd);
}
