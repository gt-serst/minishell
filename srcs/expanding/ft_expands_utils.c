/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expands_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:04:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/10/30 16:12:25 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char	*ft_handle_dquote_str(char *str, size_t *i)
// {
// 	size_t	start;

// 	start = *i;
// 	while (str[*i] != '"' && str[*i] != '$')
// 	{
// 		(*i)++;
// 	}
// 	return (ft_substr(str, start, *i - start));
// }

// char	*ft_handle_squotes(char *str, size_t *i)
// {
// 	size_t	start;

// 	start = *i;
// 	(*i)++;
// 	while (str[*i] != '\'')
// 		(*i)++;
// 	(*i)++;
// 	return (ft_substr(str, start, *i - start));
// }

char	*ft_handle_normal_str(char *str, size_t *i)
{
	size_t	start;

	start = *i;
	while (str[*i] && str[*i] != '\'' && str[*i] != '"' && str[*i] != '$')
		(*i)++;
	return (ft_substr(str, start, *i - start));
}

bool	ft_is_valid_var_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}
