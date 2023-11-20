/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/20 22:37:36 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_parsing_err_type
{
	PE_MEM,
	PE_SYNTAX
}	t_parsing_err_type;

typedef struct s_parsing_err
{
	t_parsing_err_type	type;
	char				*str;
}	t_parsing_err;

typedef enum e_node_type
{
	N_PIPE,
	N_CMD
}	t_node_type;

typedef enum e_io_node_type
{
	IO_INPUT,
	IO_OUTPUT,
	IO_HEREOC,
	IO_APPEND
}	t_io_node_type;

typedef struct s_io_node
{
	t_io_node_type		type;
	struct s_io_node	*next;
}		t_io_node;

typedef struct s_simple_cmd
{
	char	**args;
	char	**expanded_args;
	int		fdin;
	int		fdout;
}	t_simple_cmd;

typedef struct s_pipe
{
	struct s_node		*left;
	struct s_node		*right;
}	t_pipe;

typedef struct s_node_data
{
	t_simple_cmd	simple_cmd;
	t_pipe			pipe;
}	t_node_data;

typedef struct s_node
{
	t_node_type	type;
	t_node_data	data;
}	t_node;

//PARSER
t_node		*parser(void);
t_node		*ast_builder(t_io_node **io_node);
t_node		*get_simple_cmd(t_io_node **io_node);

//PARSER UTILS
void		get_next_token(void);
bool		is_pipe(void);
bool		is_redir(t_token_type type);

//ND UTILS
t_node_type		get_nd_type(t_token_type type);
t_io_node_type	get_io_nd_type(t_token_type type);
t_node			*new_nd(t_node_type type);
t_io_node		*new_io_nd(t_io_node_type type);
void			io_lstadd_back(t_io_node **io_node, t_io_node *elem);

//AST CLEANER
void		ast_cleaner(t_node **ast);
void		io_node_lstcleaner(t_io_node **io_node);

#endif
