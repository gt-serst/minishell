/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:32 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/14 10:50:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{// main function, the bash cmd requested by the user is located in arguments, the function in in charge of the core routine for minishell, the following steps will be launched read, lexer, parser, expander and execution
	(void)argc;
	(void)argv;
	init_env(envp);
	while (1)
	{
		g_minishell.cmd_line = readline("~>"); //malloc allocation in cmd_line
		if (!g_minishell.cmd_line)
			ft_exit_message("Error: Command line not found\n");
		add_history(g_minishell.cmd_line);
		g_minishell.tokens = tokenizer();
		if (g_minishell.token_err.type)
		{
			token_err_handler();
			continue ;
		}
		g_minishell.ast = parser();
		if (g_minishell.parsing_err.type)
		{
			parsing_err_handler();
			continue ;
		}
		recursive_expander(g_minishell.ast);
		recursive_redir(g_minishell.ast);
		if (g_minishell.expand_err.type)
			expanding_err_handler();
		ast_cleaner(&g_minishell.ast);
		//system("leaks minishell");
	}
	return (EXIT_SUCCESS);
}
