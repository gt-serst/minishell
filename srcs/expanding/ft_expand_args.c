/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by mde-plae          #+#    #+#             */
/*   Updated: 2023/10/31 16:07:05 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// eviter les chaines vides

char	*ft_clean_empty_strs(char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*ret;
	size_t	dstsize;

	if ((str[0] == '\'' && str[1] == '\'' && !str[2])
		|| (str[0] == '"' && str[1] == '"' && !str[2]))
		return (str);
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && str[i + 1] == '\'')
			|| (str[i] == '"' && str[i + 1] == '"'))
			i += 2;
		else
			tmp[j++] = str[i++];
	}
	free(str);
	dstsize = ft_strlen(tmp) + 1;
	ret = ft_calloc(dstsize, sizeof(char));
	return (ft_strlcpy(ret, tmp, dstsize), free(tmp), ret);
}

//gere le env_var (et va les prendre dans ft_get_envlst_char)

char	*ft_handle_dollar(char *str, size_t *i)
{
	size_t	start;
	char	*var;
	char	*env_val;

	(*i)++;
	if (ft_isdigit(str[*i]) || str[*i] == '@')
	{
		(*i)++;
		return (ft_strdup(""));
	}
	else if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(g_minishell.exit_s));
	}
	else if (!ft_is_valid_var_char(str[*i]))
		return (ft_strdup("$"));
	start = *i;
	while (ft_is_valid_var_char(str[*i]))
		(*i)++;
	var = ft_substr(str, start, *i - start);
	env_val = ft_get_envlst_val(var);
	if (!env_val)
		return (free(var), ft_strdup(""));
	return (free(var), ft_strdup(env_val));
}

// parse les ', ", $ et les normal strings

char	*ft_cmd_pre_expander(char *str)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			ret = ft_strjoin_f(ret, ft_handle_squotes(str, &i));
		else if (str[i] == '"')
			ret = ft_strjoin_f(ret, ft_handle_dquotes(str, &i));
		else if (str[i] == '$')
			ret = ft_strjoin_f(ret, ft_handle_dollar(str, &i));
		else
			ret = ft_strjoin_f(ret, ft_handle_normal_str(str, &i));
	}
	return (ret);
}

// parse dans preexpander, efface les strings vides dans cleanempty et cree un array dans expander split,
// ensuite globber gere les cas speciaux (comme * et ?) 

char	**ft_expand_args(char *str)
{
	char	**expanded;
	char	**globbed;
	size_t	i;

	str = ft_cmd_pre_expander(str);
	if (!str)
		return (NULL);
	str = ft_clean_empty_strs(str);
	if (!str)
		return (NULL);
	expanded = ft_expander_split(str);
	free(str);
	if (!expanded)
		return (NULL);
	// globbed = ft_globber(expanded);
	// if (!globbed)
	// 	return (NULL);
	// i = 0;
	// while (globbed[i])
	// {
	// 	globbed[i] = ft_strip_quotes(globbed[i]);
	// 	i++;
	// }
	// return (globbed);
}