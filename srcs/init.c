/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:06:38 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 09:50:38 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_env(char **envp)
{//init env variables and all variables from our shell to correctly start
	if (!envp)
		return (ft_exit_message("Error: Env variables not found\n"));
	//clone_env()
}
