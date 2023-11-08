/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/08 12:41:28 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*heredoc_expander(char *str)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			ret = ft_strjoin_free(ret, handle_dollar(str, &i));
		else
			ret = ft_strjoin_free(ret, handle_normal_str(str, &i));
	}
	return (ret);
}

static char	*cmd_pre_expander(char *str)
{
	char	*ret;
	size_t	i;

	printf("New str in pre expander %s\n", str);
	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			ret = ft_strjoin_free(ret, handle_squotes(str, &i));
		else if (str[i] == '"')
			ret = ft_strjoin_free(ret, handle_dquotes(str, &i));
		else if (str[i] == '$')
			ret = ft_strjoin_free(ret, handle_dollar(str, &i));
		else
			ret = ft_strjoin_free(ret, handle_normal_str(str, &i));
	}
	printf("Ret return in cmd pre expander %s\n", ret);
	return (ret);
}

static int	get_rows(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	expand_args(t_node *node)
{
	size_t	i;
	char	**expanded;

	i = 0;
	expanded = malloc(sizeof (char *) * get_rows(node->data.simple_cmd.args));
	if (!expanded)
		return (false);
	while (node->data.simple_cmd.args[i])
	{
		if (ft_strchr(node->data.simple_cmd.args[i], '$') != NULL && (i > 0)
				&& ft_strcmp(node->data.simple_cmd.args[i - 1], "<<") == 0)
		{
			expanded[i] = heredoc_expander(node->data.simple_cmd.args[i]);
			if (!expanded[i])
				return (false);
		}
		else
		{
			expanded[i] = cmd_pre_expander(node->data.simple_cmd.args[i]);
			if (!expanded[i])
				return (false);
		}
		i++;
	}
	expanded[i] = NULL;
	i = 0;
	node->data.simple_cmd.expanded_args = malloc(sizeof(char *) * get_rows(node->data.simple_cmd.args) + 1);
	if (!node->data.simple_cmd.expanded_args)
		return (false);
	ft_bzero(node->data.simple_cmd.expanded_args, sizeof(char *));
	while (expanded[i])
	{
		node->data.simple_cmd.expanded_args[i] = ft_strdup(expanded[i]);
		printf("Expanded value %s\n", node->data.simple_cmd.expanded_args[i]);
		i++;
	}
	node->data.simple_cmd.expanded_args[i] = NULL;
	ft_free_malloc(expanded);
	return (true);
}
