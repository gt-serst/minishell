/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/05 19:15:07 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_dollar(char *str, size_t *i)
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
		return (ft_itoa(g_minishell.err_code));
	}
	else if (!is_valid_var_char(str[*i]))
		return (ft_strdup("$"));
	start = *i;
	while (is_valid_var_char(str[*i]))
		(*i)++;
	var = ft_substr(str, start, *i - start);
	env_val = get_envlst_val(var);
	if (!env_val)
		return (free(var), ft_strdup(""));
	return (free(var), ft_strdup(env_val));
}

char	*cmd_pre_expander(char *str)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			ret = ft_strjoin_f(ret, handle_squotes(str, &i));
		else if (str[i] == '"')
			ret = ft_strjoin_f(ret, handle_dquotes(str, &i));
		else if (str[i] == '$')
			ret = ft_strjoin_f(ret, handle_dollar(str, &i));
		else
			ret = ft_strjoin_f(ret, handle_normal_str(str, &i));
	}
	return (ret);
}

char	**expand_args(char *str)
{
	char	**expanded;
	size_t	i;

	str = cmd_pre_expander(str);
	if (!str)
		return (NULL);
	str = clean_empty_strs(str);
	if (!str)
		return (NULL);
	expanded = expander_split(str);
	free(str);
	if (!expanded)
		return (NULL);
}
