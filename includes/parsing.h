/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/08 12:27:31 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_node_type
{
	N_PIPE,
	N_CMD
}	t_node_type;

typedef enum e_parsing_err_type
{
	PE_MEM,
	PE_SYNTAX
}	t_parsing_err_type;

typedef struct s_simple_cmd
{
	char	**args;
	char	**expanded_args;
	int		fdin;
	int		fdout;
	bool	here_doc;
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

typedef struct s_parsing_err
{
	t_parsing_err_type	type;
	char				*str;
}	t_parsing_err;

//PARSER
t_node		*parser(void);
t_node		*ast_builder(void);
t_node		*get_simple_cmd(void);

//PARSER UTILS
void		get_next_token(void);
bool		is_pipe(void);
bool		is_redir(t_token_type type);

//ND UTILS
t_node_type	get_nd_type(t_token_type type);
t_node		*new_nd(t_node_type type);

//AST CLEANER
void		ast_cleaner(t_node **ast);

#endif
