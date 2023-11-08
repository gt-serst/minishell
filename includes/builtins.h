/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:38:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/06 10:38:52 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../../minishell.h"

int		env();
// int		export();
int		echo();
int		unset();
int		pwd(void);
int		cd();

void	exit_minishell();

// char	**alloc_and_assign_new_env(char **original_env, char *cmd);
// int		set_env_condition(char *cmd, char *env);

#endif