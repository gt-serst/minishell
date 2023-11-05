/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:23:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/05 16:26:43 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	launch_expander(t_node *node)
{

}


bool	recursive_expander(t_node *node)
{
	if (node->type == N_CMD)
	{
		if (!launch_expander(node))
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
