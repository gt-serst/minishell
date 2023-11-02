/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/02 11:19:32 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// eviter les chaines vides

char	*ft_empty_strs(char *str)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*ret;
	size_t	dstsize;

	if ((str[0] == '\'' && str[1] == '\'' && !str[2])
		|| (str[0] == '"' && str[1] == '"' && !str[2]))
		return (str);
	tmp = malloc((ft_strlen(str) + 1) * sizeof(char));
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
	ret = malloc(dstsize * sizeof(char));
	//possible?
	return (ft_strlcpy(ret, tmp, dstsize), free(tmp), ret);
}

//gere le env_var (et va les prendre dans ft_get_envlst_char)

char	*ft_dollar(char *str, size_t *i)
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
	env_val = ft_envlst_val(var);
	if (!env_val)
		return (free(var), ft_strdup(""));
	return (free(var), ft_strdup(env_val));
}

// parse les ', ", $ et les normal strings

char	*ft_pre_expander(char *str)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			ret = ft_strjoin_f(ret, ft_squotes(str, &i));
		else if (str[i] == '"')
			ret = ft_strjoin_f(ret, ft_dquotes(str, &i));
		else if (str[i] == '$')
			ret = ft_strjoin_f(ret, ft_dollar(str, &i));
		else
			ret = ft_strjoin_f(ret, ft_normal_str(str, &i));
	}
	return (ret);
}

// parse dans preexpander, efface les strings vides dans cleanempty et cree un array dans expander split,

char	**ft_expand_args(char *str)
{
	char	**expanded;
	size_t	i;

	str = ft_pre_expander(str);
	if (!str)
		return (NULL);
	str = ft_empty_strs(str);
	if (!str)
		return (NULL);
	expanded = ft_split_expander(str);
	free(str);
	if (!expanded)
		return (NULL);
	return (expanded)
}
