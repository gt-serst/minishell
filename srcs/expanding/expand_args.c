/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by mde-plae          #+#    #+#             */
/*   Updated: 2024/04/29 15:50:45 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
			return (error(E_MEM, NULL, NULL, m), NULL);
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

static char	*expand_argument(t_minishell *m, char **args, size_t i)
{
	if (ft_strchr(args[i], '$') != NULL && (i > 0) && ft_strcmp(args[i - 1], "<<") == 0)
		return (ft_strdup(args[i]));
	else
		return (cmd_pre_expander(m, args[i]));
}

bool	expand_args(t_minishell *m, t_node *node)
{
	size_t	i;

	i = 0;
	node->data.simple_cmd.expanded_args
		= malloc(sizeof(char *) * (get_rows(node->data.simple_cmd.args) + 1));
	if (!node->data.simple_cmd.expanded_args)
		return (error(E_MEM, NULL, NULL, m), false);
	ft_bzero(node->data.simple_cmd.expanded_args, sizeof(char *));
	while (node->data.simple_cmd.args[i])
	{
		node->data.simple_cmd.expanded_args[i]
			= expand_argument(m, node->data.simple_cmd.args, i);
		if (!node->data.simple_cmd.expanded_args[i])
			return (false);
		i++;
	}
	node->data.simple_cmd.expanded_args[i] = NULL;
	return (true);
}
