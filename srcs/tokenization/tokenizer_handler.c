/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/08 16:18:04 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
static int	separator_handler(t_token **t, char *substr, t_token_type type)
{//create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	t_token	*token;

	token = new_tk(substr, type); //malloc allocation in tk
	if (!token)
		return (0);
	return (1);
}
*/
t_token	*separator_handler(char	**cmd_line)
{// retrieve the type of separator and called the separator_handler
	size_t	i;
	char	*substr;
	char	*tmp;

	i = 0;
	tmp = *cmd_line;
	while (tmp[i] && ft_ismetachar(tmp + i))
		i++;
	substr = ft_substr(tmp, 0, i - 1); //malloc allocation in substr
	if (!substr)
		return (NULL);
	*cmd_line += i;
	if (ft_strcmp(substr, "<") == 0)
		return (new_tk(substr, T_INPUT));
	else if (ft_strcmp(substr, ">") == 0)
		return (new_tk(substr, T_OUTPUT));
	else if (ft_strcmp(substr, "<<") == 0)
		return (new_tk(substr, T_HEREDOC));
	else if (ft_strcmp(substr, ">>") == 0)
		return (new_tk(substr, T_APPEND));
	else
		return (new_tk(substr, T_PIPE)); //malloc allocation in token
}

t_token	*identifier_handler(char **cmd_line)
{// create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	size_t	i;
	char	*substr;
	char	*tmp;

	i = 0;
	tmp = *cmd_line;
	while (tmp[i] && !ft_ismetachar(tmp + i))
	{
		if (ft_isquotes(tmp[i]))
		{
			if (!skip_quotes(tmp, &i))
				return (NULL);
		}
		else
			i++;
	}
	substr = ft_substr(*cmd_line, 0, i); //malloc allocation in substr
	if (!substr)
		return (NULL);
	*cmd_line += i;
	return (new_tk(substr, T_IDENTIFIER)); //malloc allocation in token
}
