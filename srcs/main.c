/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:32 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/21 18:36:34 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{// main function, the bash cmd requested by the user is located in arguments, the function in in charge of the core routine for minishell, the following steps will be launched read, lexer, parser, expander and execution
	t_minishell	mini;
	t_prompt	prompt;

	(void)argc;
	(void)argv;
	init_env(envp);
	while (1)
	{
		prompt.cmd_line = readline("~>"); //malloc allocation in cmd_line
		if (!prompt.cmd_line)
			ft_exit_message("Error: Command line not found\n");
		if (prompt.cmd_line[0])
			add_history(prompt.cmd_line);
		mini.token = tokenizer(prompt);
		if (!mini.token)
			continue ;
		mini.ast = parser(mini.token);
		if (!mini.ast)
			continue ;
		if (!exec_ast(mini.ast));
			continue ;
		shell_cleaner();
		//system("leaks minishell");
	}
	return (EXIT_SUCCESS);
}
