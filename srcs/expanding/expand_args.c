/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/15 11:33:43 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*heredoc_expander(char *str)
{
	char	*ret;
	size_t	i;

	if (g_minishell.expand_err.type)
		return (NULL);
	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			ret = ft_strjoin_free(ret, handle_dollar(str, &i));
		else
			ret = ft_strjoin_free(ret, handle_normal_str(str, &i));
		if (!ret)
			return (set_expand_err(EE_MEM), NULL);
	}
	return (ret);
}

static char	*cmd_pre_expander(char *str)
{
	char	*ret;
	size_t	i;

	if (g_minishell.expand_err.type)
		return (NULL);
	// printf("New str in pre expander %s\n", str);
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
		if (!ret)
			return (set_expand_err(EE_MEM), NULL);
	}
	// printf("Ret return in cmd pre expander %s\n", ret);
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
	// char	**expanded;

	printf("Enterering in expander\n");
	i = 0;
	node->data.simple_cmd.expanded_args = malloc(sizeof (char *) * get_rows(node->data.simple_cmd.args));
	if (!node->data.simple_cmd.expanded_args)
		return (set_expand_err(EE_MEM), false);
	//ft_bzero(node->data.simple_cmd.expanded_args, sizeof(char *));
	while (node->data.simple_cmd.args[i])
	{
		if (ft_strchr(node->data.simple_cmd.args[i], '$') != NULL && (i > 0)
				&& ft_strcmp(node->data.simple_cmd.args[i - 1], "<<") == 0)
		{
			node->data.simple_cmd.expanded_args[i] = heredoc_expander(node->data.simple_cmd.args[i]);
			if (!node->data.simple_cmd.expanded_args[i])
				return (false);
		}
		else
		{
			node->data.simple_cmd.expanded_args[i] = cmd_pre_expander(node->data.simple_cmd.args[i]);
			if (!node->data.simple_cmd.expanded_args[i])
				return (false);
		}
		printf("Expanded value %s\n", node->data.simple_cmd.expanded_args[i]);
		i++;
	}
	node->data.simple_cmd.expanded_args[i] = NULL;
	printf("EXPANDED AST\n");
	ft_print_expanded_ast(node);
	// for (int j = 0; j < get_rows(node->data.simple_cmd.expanded_args); j++)
	// {
	// 	printf("Index %d : string %s\n", j, node->data.simple_cmd.expanded_args[j]);
	// }
/*
	printf("%zu\n\n", i);
	expanded[i] = NULL;
	node->data.simple_cmd.expanded_args = malloc(sizeof(char *) * (get_rows(node->data.simple_cmd.args) + 1));
	printf("get rows = %i\n", get_rows(node->data.simple_cmd.args));
	if (!node->data.simple_cmd.expanded_args)
		return (set_expand_err(EE_MEM), false);
	//ft_bzero(node->data.simple_cmd.expanded_args, sizeof(char *));
	i = 0;
	printf("%s\n", expanded[2]);
	while (expanded[i] && printf("%s\n", expanded[i]))
	{
		printf("%zu\n", i);
		printf("Nouvel elem %s\n", expanded[i]);
		node->data.simple_cmd.expanded_args[i] = ft_strdup(expanded[i]);
		printf("Expanded value %s\n", node->data.simple_cmd.expanded_args[i]);
		i++;
	}
	printf("here\n");
	node->data.simple_cmd.expanded_args[i] = NULL;
	printf("finished\n");
	//ft_free_malloc(expanded);
*/
	return (true);
}
