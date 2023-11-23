/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/23 13:50:27 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*heredoc_expander(t_minishell *m, char *str)
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
			ret = ft_strjoin_free(ret, handle_normal_str(str, &i));
		if (!ret)
			return (error(E_MEM, NULL, NULL), NULL);
	}
	return (ret);
}

static char	*cmd_pre_expander(t_minishell *m, char *str)
{
	char	*ret;
	size_t	i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			ret = ft_strjoin_free(ret, handle_squotes(str, &i));
		else if (str[i] == '"')
			ret = ft_strjoin_free(ret, handle_dquotes(m, str, &i));
		else if (str[i] == '$')
			ret = ft_strjoin_free(ret, handle_dollar(m, str, &i));
		else
			ret = ft_strjoin_free(ret, handle_normal_str(str, &i));
		if (!ret)
			return (error(E_MEM, NULL, NULL), NULL);
	}
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

bool	expand_args(t_minishell *m, t_node *node)
{
	size_t	i;

	i = 0;
	node->data.simple_cmd.expanded_args = malloc(sizeof (char *) * (get_rows(node->data.simple_cmd.args) + 1));
	if (!node->data.simple_cmd.expanded_args)
		return (error(E_MEM, NULL, NULL), false);
	ft_bzero(node->data.simple_cmd.expanded_args, sizeof(char *));
	while (node->data.simple_cmd.args[i])
	{
		if (ft_strchr(node->data.simple_cmd.args[i], '$') != NULL && (i > 0)
				&& ft_strcmp(node->data.simple_cmd.args[i - 1], "<<") == 0)
		{
			node->data.simple_cmd.expanded_args[i] = heredoc_expander(m, node->data.simple_cmd.args[i]);
			if (!node->data.simple_cmd.expanded_args[i])
				return (false);
		}
		else
		{
			node->data.simple_cmd.expanded_args[i] = cmd_pre_expander(m, node->data.simple_cmd.args[i]);
			if (!node->data.simple_cmd.expanded_args[i])
				return (false);
		}
		i++;
	}
	node->data.simple_cmd.expanded_args[i] = NULL;
	//ft_print_expanded_ast(node);
	return (true);
}
