/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:13 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/17 14:28:38 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "tokenization.h"
#include "parsing.h"

typedef struct s_minishell
{
	t_node	**ast;
	t_token	**tokens;
}		t_minishell;

#endif