/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 15:49:15 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	separator_handler(t_minishell *m, char *sep, t_token_type type)
{//create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	t_token	*tk;

	tk = new_tk(sep, type); //malloc allocation in tk
	free(sep);
	if (!tk)
		ft_exit_message("Error: token elem not created");
	tkadd_back(&m->tokens, tk);
}

void	separator_recognizer(t_minishell *m, char	*cmd_line)
{// retrieve the type of separator and called the separator_handler
	int		count;
	char	*substr;
	char	*tmp;

	count = 0;
	tmp = cmd_line;
	while (*tmp && !ft_isspace(*tmp++))
		count++;
	substr = ft_substr(cmd_line, 0, count); //malloc allocation in substr
	//printf("%s\n", substr);
	if (ft_strncmp(substr, "<", ft_strlen(substr)) == 0)
		separator_handler(m, substr, T_LESS);
	else if (ft_strncmp(substr, ">", ft_strlen(substr)) == 0)
		separator_handler(m, substr, T_GREAT);
	else if (ft_strncmp(substr, "<<", ft_strlen(substr)) == 0)
		separator_handler(m, substr, T_DLESS);
	else if (ft_strncmp(substr, ">>", ft_strlen(substr)) == 0)
		separator_handler(m, substr, T_DGREAT);
	else if (ft_strncmp(substr, "|", ft_strlen(substr)) == 0)
		separator_handler(m, substr, T_PIPE);
	else if (ft_strncmp(substr, "(", ft_strlen(substr)) == 0)
		separator_handler(m, substr, T_LPAREN);
	else if (ft_strncmp(substr, ")", ft_strlen(substr)) == 0)
		separator_handler(m, substr, T_RPAREN);
	else
		return (ft_exit_message("Error: type of separator not found"));
}

void	identifier_handler(t_minishell *m, char *cmd_line)
{// create a tk and add it to the linkded list and then allocate a type of token to the cmd part
	int		count;
	char	*substr;
	char	*tmp;
	t_token	*tk;

	count = 0;
	tmp = cmd_line;
	while (*tmp && !ft_isspace(*tmp++))
		count++;
	substr = ft_substr(cmd_line, 0, count); //malloc allocation in substr
	//printf("%s\n", substr);
	tk = new_tk(substr, T_IDENTIFIER); //malloc allocation in tk
	free(substr);
	if (!tk)
		ft_exit_message("Error: token elem not created");
	tkadd_back(&m->tokens, tk);
}
