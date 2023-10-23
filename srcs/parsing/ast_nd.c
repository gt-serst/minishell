/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_nd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:24:59 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/23 12:19:41 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_io_list(t_io_node **io_list)
{
	//while (is_redir())
	//	redir_type = g_minishell.curr_token->type;
	//	get_next_token();
	//	tmp_io_node = ft_new_io_node(redir_type, g_minishell.curr_token->value);
	//	ft_append_io_node(io_list, tmp_io_node);
	//	ft_get_next_token();
	//return true
}

bool	join_args(char **args)
{
	//while (IDENTIFIER)
	//	ft_join()
	//	get_next_token()
	//return true
}

t_node	*get_simple_cmd(void)
{// get the cmd and the cmd args of the simple cmd then create a tree node
	//new_node()
	//while (curr_token_type == IDENTIFIER || == is_redir(curr_token->type))
	//	if (IDENTIFIER)
	//		join_args()
	//	if (is_redir())
	//		get_io_list()
	//return (node)
}
