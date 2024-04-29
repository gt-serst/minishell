/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:45:52 by gt-serst          #+#    #+#             */
/*   Updated: 2024/04/29 14:52:09 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//	parser
t_node			*parser(t_minishell *m);
t_node			*ast_builder(t_token **curr_token, t_minishell *m);
t_node			*error_unexpected_token(t_token **curr_token, t_minishell *m);
t_node			*get_simple_cmd(t_token **curr_token, t_minishell *m);

//	parser utils
void			get_next_token(t_token **curr_token);
bool			is_pipe(t_token *curr_token);
bool			is_redir(t_token_type type);

//	node utils
t_node_type		get_nd_type(t_token_type type);
t_io_node_type	get_io_nd_type(t_token_type type);
t_node			*new_nd(t_node_type type);
t_io_node		*new_io_nd(t_io_node_type type);
void			io_lstadd_back(t_io_node **io_node, t_io_node *elem);

//	cleaner
void			ast_cleaner(t_node **ast);
void			io_node_lstcleaner(t_io_node **io_node);

#endif
