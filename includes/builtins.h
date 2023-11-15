/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:38:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/15 16:37:38 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// echo
int 			ft_echo(char **args);
// cd
int				ft_cd(char *path);
// pwd
int				ft_pwd(void);
// exit
void			ft_exit(char **args);
// export
int				ft_export(char **argv);
// unset
int				ft_unset(char **args);
// env & env_utils
int				ft_env(void);
void			update_envlst(char *key, char *value, bool create);
char			*envlst_val(char *key);
void			*envlst_handler(void *ptr, bool clean);
void			envlst_init(void);
bool			env_exists(char *key);
char			*env_value(char *str);
char			*env_key(char *str);

#endif
