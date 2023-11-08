/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:24:26 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/08 12:21:55 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*env_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '=')
}

void	envlst_init(void)
{
	char	**envlst;

	i = 0;
	envlst = t_minishell.environ;
	if (!envlst)
		return ;
	while (envlst)
	{
		key = env_key(envlst[i]);
		value = env_value(envlst[i]);
		update_envlst(key, value, true);
		i++;
	}
}