/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:32 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/18 20:04:08 by geraudtsers      ###   ########.fr       */
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
		if (g_minishell.cmd_line[0])
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
		exec_ast(g_minishell.ast);
		if (g_minishell.expand_err.type)
			expanding_err_handler();
		if (g_minishell.exec_err.type)
			exec_err_handler();
		shell_cleaner();
		//system("leaks minishell");
	}
	return (EXIT_SUCCESS);
}
