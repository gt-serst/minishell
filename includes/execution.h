/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:14:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/10/26 15:37:23 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//	execution
void	ft_exec(void);
void	ft_ast_init(t_node *node);
void	ft_leaf_init(t_node *node);

//	expander
char	**ft_expand_args(char *str);


#endif