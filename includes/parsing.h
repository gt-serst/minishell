/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/17 14:28:29 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include "minishell.h"
#include "tokenization.h"

typedef enum e_node_type
{
	NODE_CMD,
	NODE_CHILD,
}	t_node_type;

typedef struct s_simple_cmd
{
	char	**argv;
	int		fdin;
	int		fdout;
}	t_simple_cmd;

typedef struct s_children
{
	struct s_node	*left;
	struct s_node	*right;
}	t_children;

typedef struct s_node_data
{
	t_simple_cmd	simple_cmd;
	t_children		child;
}	t_node_data;

typedef struct s_node
{
	t_node_type	type;
	t_node_data	data;
}	t_node;

#endif
