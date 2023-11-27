/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:47:14 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 14:56:25 by mde-plae         ###   ########.fr       */
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
