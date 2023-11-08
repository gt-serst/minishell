/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:38:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/08 15:45:11 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../../minishell.h"

int 			ft_echo(char **args);
static bool		is_option_n(char *s);
static int		ft_cd(char *path);
static int		cd_home_user(void);
static int		new_pwd(void);
int				ft_pwd(void);

// env & env_utils

int				ft_env(void);
void			envlst_init(void);
char			*env_value(char *str);
char			*env_key(char *str);
void			update_envlst(char *key, char *value, bool create);
void			envlst_back(t_env *new);
void			*envlst_handler(void *ptr, bool clean);
static t_env	*new_envlst(char *key, char *value);
char			*envlst_val(char *key);

#endif