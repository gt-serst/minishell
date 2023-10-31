/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/31 08:53:24 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	separator_handler(t_token **t, char *substr, t_token_type type)
{//create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	t_token	*token;

	token = new_tk(substr, type); //malloc allocation in tk
	if (!token)
		return (0);
	tkadd_back(t, token);
	return (1);
}

int	separator_recognizer(t_token **t, char	**cmd_line)
{// retrieve the type of separator and called the separator_handler
	int		i;
	char	*substr;
	char	*tmp;

	i = 0;
	tmp = *cmd_line;
	while (tmp[i] && !ft_isspace(tmp[i]))
		i++;
	substr = ft_substr(tmp, 0, i); //malloc allocation in substr
	if (!substr)
		return (0);
	*cmd_line += i;
	if (ft_strncmp(substr, "<", ft_strlen(substr)) == 0)
		return (separator_handler(t, substr, T_LESS));
	else if (ft_strncmp(substr, ">", ft_strlen(substr)) == 0)
		return (separator_handler(t, substr, T_GREAT));
	else if (ft_strncmp(substr, "<<", ft_strlen(substr)) == 0)
		return (separator_handler(t, substr, T_DLESS));
	else if (ft_strncmp(substr, ">>", ft_strlen(substr)) == 0)
		return (separator_handler(t, substr, T_DGREAT));
	else if (ft_strncmp(substr, "|", ft_strlen(substr)) == 0)
		return (separator_handler(t, substr, T_PIPE));
	else
		return (0);
}

int	identifier_handler(t_token **t, char **cmd_line)
{// create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	size_t	i;
	char	*substr;
	char	*tmp;
	t_token	*token;
	char	quote;

	i = 0;
	tmp = *cmd_line;
	if (ft_isquotes(tmp[i]))
	{
		quote = tmp[i];
		i++;
		while (tmp[i] && tmp[i] != quote)
			i++;
		if (tmp[i] == quote)
		{
			i++;
			substr = ft_substr(tmp, 1, i - 2);
			if (!substr)
				return (0);
		}
		else
			return (quotes_err_message(quote), 0);
	}
	else
	{
		while (tmp[i] && !ft_isspace(tmp[i]))
			i++;
		substr = ft_substr(*cmd_line, 0, i); //malloc allocation in substr
		if (!substr)
			return (0);
	}
	token = new_tk(substr, T_IDENTIFIER); //malloc allocation in tk
	if (!token)
		return (0);
	tkadd_back(t, token);
	*cmd_line += i;
	return (1);
}
