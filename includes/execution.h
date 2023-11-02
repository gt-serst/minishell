/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:14:07 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/02 11:39:25 by mde-plae         ###   ########.fr       */
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
char	*ft_pre_expander(char *str);
char	*ft_strjoin_f(char *s1, char *s2);
char	*ft_dquote_str(char *str, size_t *i);
char	*ft_squotes(char *str, size_t *i);
char	*ft_normal_str(char *str, size_t *i);
bool	ft_is_valid_var_char(char c);
char	*ft_empty_strs(char *str);
char	**ft_split_expander(char const *s);
void	ft_skip_word(char const *s, size_t	*i);
char	**ft_allocater(char const *s, char **strs);
char	**ft_filler(char const *s, char **strs);
void	ft_words_filler(const char *s, char **strs, size_t *i, size_t j);

#endif