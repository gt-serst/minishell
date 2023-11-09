/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:38:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/09 15:34:19 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// echo
int 			ft_echo(char **args);
static bool		is_option_n(char *s);
// cd
static int		ft_cd(char *path);
static int		cd_home_user(void);
static int		new_pwd(void);
// pwd
int				ft_pwd(void);
// exit
void			ft_exit(char **args);
static int		exitnbr(char *str);
void			atoi_skip(char *s, int *i, int *sign);
static bool		ft_isnumber(char *s);
// export
int				ft_export(char **argv);
int				check_key(char *str);
static void		declare_envlst(void);
static int		export_err_msg(char *err);
// unset
int				ft_unset(char **args);
static void		unset_env(char *key);
// env & env_utils
int				ft_env(void);
void			envlst_init(void);
char			*env_value(char *str);
char			*env_key(char *str);
void			update_envlst(char *key, char *value, bool create);
void			envlst_back(t_env *new);
void			*envlst_handler(void *ptr);
static t_env	*new_envlst(char *key, char *value);
char			*envlst_val(char *key);

#endif