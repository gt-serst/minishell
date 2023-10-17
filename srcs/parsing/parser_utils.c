/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:10:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/17 17:22:28 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_next_token(void)
{// get the next token of the tokens list
}

bool	is_pipe(void)
{// if is a pipe return 1 else 0
}

bool	is_redir(t_token_type type)
{// if is a redirection return 1 else 0
}

bool	get_io_list(t_io_node **io_list)
{
}

t_node	*get_simple_cmd(void)
{// get the cmd and the cmd args of the simple cmd then create a tree node
}
