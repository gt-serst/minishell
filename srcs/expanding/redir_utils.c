/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:47:14 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/27 18:01:13 by gt-serst         ###   ########.fr       */
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

bool	is_delimiter(char *delimiter, char *line)
{
	if (!line || ft_strcmp(line, "") == 0)
		return (false);
	while (*line)
	{
		if (*delimiter == '"' || *delimiter == '\'')
		{
			delimiter++;
			continue ;
		}
		else if (*line == *delimiter)
		{
			line++;
			delimiter++;
		}
		else
			return (false);
	}
	return (true);
}

char	*heredoc_handle_normal_str(char *str, size_t *i)
{
	size_t	start;

	start = *i;
	while (str[*i] && str[*i] != '$')
		(*i)++;
	return (ft_substr(str, start, *i - start));
}
// remove simple and double quotes for a random str without envars to carry

char	*heredoc_expander(t_minishell *m, char *str)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			ret = ft_strjoin_free(ret, handle_dollar(m, str, &i));
		else
			ret = ft_strjoin_free(ret, heredoc_handle_normal_str(str, &i));
		if (!ret)
			return (error(E_MEM, NULL, NULL, m), NULL);
	}
	return (ret);
}
