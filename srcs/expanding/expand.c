/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:23:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 11:36:34 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_dollar(t_minishell *m, char *str, size_t *i)
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
		return (ft_itoa(m->err_code));
	}
	else if (!is_valid_var_char(str[*i]))
		return (ft_strdup("$"));
	start = *i;
	while (is_valid_var_char(str[*i]))
		(*i)++;
	var = ft_substr(str, start, *i - start);
	env_val = envlst_val(&m->envlst, var);
	if (!env_val)
		return (free(var), ft_strdup(""));
	return (free(var), ft_strdup(env_val));
}
// handle particular case like $ + digit, $ + @, $ + ? and $ 
// + non-numerical then get the value of 
// the envar to replace it in str

bool	recursive_expander(t_minishell *m, t_node *node)
{
	if (!node)
		return (false);
	if (node->type == N_CMD)
	{
		if (!expand_args(m, node))
			return (false);
	}
	if (node->data.pipe.left != NULL)
	{
		if (!recursive_expander(m, node->data.pipe.left))
			return (false);
		if (!recursive_expander(m, node->data.pipe.right))
			return (false);
	}
	return (true);
}
