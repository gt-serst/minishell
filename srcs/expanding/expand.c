/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:23:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/08 10:27:38 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	recursive_expander(t_node *node)
{
	if (!node)
		return (false);
	if (node->type == N_CMD)
	{
		printf("Command enter in expander %s\n", node->data.simple_cmd.args[0]);
		if (!expand_args(node))
			return (false);
	}
	else
	{
		if (node->data.pipe.left != NULL)
			if (!recursive_expander(node->data.pipe.left))
				return (false);
		if (node->data.pipe.right != NULL)
			if (!recursive_expander(node->data.pipe.right))
				return (false);
	}
	return (true);
}