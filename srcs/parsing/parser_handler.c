/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:24:59 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/14 14:57:27 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
static char	*join_with_char(char *s1, char *s2, char c)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = c;
	i = 0;
	while (s2[i])
		str[j++] = *s2++;
	str[j] = '\0';
	return (str);
}
*/

int	arglen(void)
{
	t_token	*token;
	int		res;

	token = g_minishell.curr_token;
	res = 0;
	while (token && (token->type == T_IDENTIFIER
			|| is_redir(token->type)))
	{
		res++;
		token = token->next;
	}
	return (res);
}

static bool	token_into_args(t_node* simple_cmd)
{
	int	i;

	i = -1;
	if (g_minishell.parsing_err.type)
		return (false);
	simple_cmd->data.simple_cmd.args = malloc(sizeof(char *) * (arglen() + 1));
	if (!simple_cmd->data.simple_cmd.args)
		return (set_parsing_err(PE_MEM), false);
	//ft_bzero(simple_cmd->data.simple_cmd.args, sizeof(char *));
	while (g_minishell.curr_token && (g_minishell.curr_token->type == T_IDENTIFIER
		|| is_redir(g_minishell.curr_token->type)))
	{
		simple_cmd->data.simple_cmd.args[++i] = ft_strdup(g_minishell.curr_token->value);
		get_next_token();
	}
	simple_cmd->data.simple_cmd.args[++i] = NULL;
	return (true);
}

t_node	*get_simple_cmd(void)
{// get the cmd and the cmd args of the simple cmd then create a tree node
	t_node	*simple_cmd;

	if (g_minishell.parsing_err.type)
		return (NULL);
	simple_cmd = new_nd(N_CMD);
	if (!simple_cmd)
		return (set_parsing_err(PE_MEM), NULL);
	while (g_minishell.curr_token && (g_minishell.curr_token->type == T_IDENTIFIER
		|| is_redir(g_minishell.curr_token->type)))
	{
		simple_cmd->data.simple_cmd.fdin = STDIN_FILENO;
		simple_cmd->data.simple_cmd.fdout = STDOUT_FILENO;
		if (!token_into_args(simple_cmd))
			return (set_parsing_err(PE_MEM), NULL);
	}
	return (simple_cmd);
}
