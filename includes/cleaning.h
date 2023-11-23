/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:15:03 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 13:56:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

//	cleaning
void	shell_cleaner(t_minishell *m);
void	shell_shutdown(t_minishell *m);
void	envlst_cleaner(t_env **envlst);

#endif
