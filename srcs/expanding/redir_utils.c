/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:47:14 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 13:23:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	arg_is_redir(char *arg)
{
	if (ft_strcmp(arg, "<") == 0 || ft_strcmp(arg, "<<") == 0
			|| ft_strcmp(arg, ">") == 0 || ft_strcmp(arg, ">>") == 0)
		return (true);
	return (false);
}
