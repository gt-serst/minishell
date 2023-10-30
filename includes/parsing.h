/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/30 13:06:17 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

typedef enum e_node_type
{
	N_PIPE,
	N_CMD
}	t_node_type;

typedef enum e_io_type
{
	IO_IN,
	IO_OUT,
	IO_HEREDOC,
	IO_APPEND
}	t_io_type;

typedef enum e_parsing_err_type
{
	E_MEM,
	E_SYNTAX
}	t_parsing_err_type;

typedef struct s_io_node
{
	t_io_type			type;
	char				*value;
	char				**expanded_value;
	int					here_doc;
	struct s_io_node	*prev;
	struct s_io_node	*next;
}	t_io_node;

typedef struct s_node
{
	t_node_type			type;
	t_io_node			*io_list;
	char				*args;
	char				**expanded_args;
	struct s_node		*left;
	struct s_node		*right;
}	t_node;

typedef struct s_parsing_err
{
	t_parsing_err_type	type;
	char				*str;
}	t_parsing_err;

//PARSER
t_node		*parser();
t_node		*prec_climbing();
t_node		*get_simple_cmd(void);

//PARSER UTILS
void		get_next_token(void);
bool		is_op(void);
bool		is_redir(t_token_type type);

//ND UTILS
t_node_type	get_node_type(t_token_type type);
t_io_type	get_io_type(t_token_type type);
t_node		*new_node(t_node_type type);
t_io_node	*new_io_node(t_io_type type, char *value);
void		addback_io_node(t_io_node **lst, t_io_node *new);

//PARSING ERR
void		set_parsing_err(t_parsing_err_type type);
t_node		*parsing_err_handler(void);

//CLEAR AST
void		clear_ast(t_node **ast);

#endif
