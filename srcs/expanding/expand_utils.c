/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:04:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/22 16:16:26 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_dollar(t_minishell *m, char *str, size_t *i)
{// handle particular case like $ + digit, $ + @, $ + ? and $ + non-numerical then get the value of the envar to replace it in str
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
		return (ft_itoa(m->err_code));
	}
	else if (!is_valid_var_char(str[*i]))
		return (ft_strdup("$"));
	start = *i;
	while (is_valid_var_char(str[*i]))
		(*i)++;
	var = ft_substr(str, start, *i - start);
	env_val = envlst_val(m->envlst, var);
	if (!env_val)
		return (free(var), ft_strdup(""));
	return (free(var), ft_strdup(env_val));
}

static char	*handle_normal_dquotes(char *str, size_t *i)
{// only pass through double quotes and still get the $ to enter in handle_dollar in the next while loop
	size_t	start;

	start = *i;
	while (str[*i] != '"' && str[*i] != '$')
		(*i)++;
	return (ft_substr(str, start, *i - start));
}

char	*handle_squotes(char *str, size_t *i)
{// pass through simple quotes and also $ to avoid enter in handle_dollar and do not display the envar
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
	// printf("Ret %s\n", ret);
	return (ft_strjoin_free(ret, ft_strdup("")));
}

char	*handle_normal_str(char *str, size_t *i)
{// remove simple and double quotes for a random str without envars to carry
	size_t	start;

	start = *i;
	while (str[*i] && str[*i] != '\'' && str[*i] != '"' && str[*i] != '$' && str[*i] != '\\')
		(*i)++;
	// printf("Substr return in handle normal str |%s|\n", ft_substr(str, start, *i - start));
	return (ft_substr(str, start, *i - start));
}

bool	is_valid_var_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}
