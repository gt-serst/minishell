/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:32 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/30 14:40:42 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell	g_minishell;

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
		if (!g_minishell.tokens)
			continue ;
		g_minishell.ast = parser();
		 if (g_minishell.parsing_err.type)
		 {
			parsing_err_handler();
		 	continue ;
		 }
	}
	return (EXIT_SUCCESS);
}
