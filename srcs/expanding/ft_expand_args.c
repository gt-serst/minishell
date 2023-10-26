/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by mde-plae          #+#    #+#             */
/*   Updated: 2023/10/26 16:55:47 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_cmd_pre_expander(char *str)
{
	char	*ret;
	int		i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		
	}
}

char	**ft_expand_args(char *str)
{
	str = ft_cmd_pre_expander(str);
}