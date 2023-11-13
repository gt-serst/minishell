/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:42:16 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/13 15:47:23 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#include "minishell.h"

void		ft_exit_message(char *s);
void		quotes_err_message(char c);
void		set_parsing_err(t_parsing_err_type type);
void		parsing_err_handler(void);
void		set_expand_err(t_expand_err_type type);
void		expanding_err_handler(void);
int			export_err_message(char *s);
void		set_exec_err(t_exec_err_type type);
void		exec_err_handler(void);

#endif
