/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:38:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/12/28 19:26:40 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//	echo
int		ft_echo(char **args);

//	cd
int		ft_cd(t_env **envlst, char *path);

//	pwd
int		ft_pwd(void);

//	exit
void	ft_exit(t_minishell *m, char **args, bool piped);

//	export
int		ft_export(t_env **envlst, char **argv, t_minishell *m);

//	unset
int		ft_unset(t_env **env, char **args);

//	env & env_utils
int		ft_env(t_env **envlst);
void	update_envlst(t_env **envlst, char *key, char *value, bool create);
char	*envlst_value(t_env **envlst, char *key);
void	*garbage_collector(void *ptr, bool clean);
void	envlst_init(t_env **envlst, char **env);
bool	env_exists(t_env **envlst, char *key);
char	*get_env_value(char *str);
char	*get_env_key(char *str);
int		check_key(char *str);

#endif
