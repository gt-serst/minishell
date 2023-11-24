/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:04:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/24 11:37:51 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*handle_normal_dquotes(char *str, size_t *i)
{
	size_t	start;

	start = *i;
	while (str[*i] != '"' && str[*i] != '$')
		(*i)++;
	return (ft_substr(str, start, *i - start));
}
// only pass through double quotes and 
// still get the $ to enter in handle_dollar in the next while loop

char	*handle_squotes(char *str, size_t *i)
{
	char	*substr;
	size_t	start;

	(*i)++;
	start = *i;
	while (str[*i] != '\'')
		(*i)++;
	substr = ft_substr(str, start, *i - start);
	if (!substr)
		return (NULL);
	(*i)++;
	return (substr);
}
// pass through simple quotes and also $ 
// to avoid enter in handle_dollar and do not display the envar

char	*handle_dquotes(t_minishell *m, char *str, size_t *i)
{
	char	*ret;

	ret = ft_strdup("");
	(*i)++;
	while (str[*i] != '"')
	{
		if (str[*i] == '$')
			ret = ft_strjoin_free(ret, handle_dollar(m, str, i));
		else
			ret = ft_strjoin_free(ret, handle_normal_dquotes(str, i));
	}
	(*i)++;
	return (ft_strjoin_free(ret, ft_strdup("")));
}

char	*handle_normal_str(char *str, size_t *i)
{
	size_t	start;

	start = *i;
	while (str[*i] && str[*i] != '\'' && 
		str[*i] != '"' && str[*i] != '$' && str[*i] != '\\')
		(*i)++;
	return (ft_substr(str, start, *i - start));
}
// remove simple and double quotes 
// for a random str without envars to carry

bool	is_valid_var_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}
