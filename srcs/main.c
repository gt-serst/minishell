/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:32 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/23 14:45:53 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{// main function, the bash cmd requested by the user is located in arguments, the function in in charge of the core routine for minishell, the following steps will be launched read, lexer, parser, expander and execution
	t_minishell	m;

	(void)argc;
	(void)argv;
	init_env(&m, envp);
	while (1)
	{
		// signals_init();
		m.cmd_line = readline("~>"); //malloc allocation in cmd_line
		if (!m.cmd_line)
			ft_exit_message("bash: command line not found\n");
		if (m.cmd_line[0])
			add_history(m.cmd_line);
		m.token = tokenizer(&m);
		if (!m.token)
			continue ;
		m.ast = parser(&m);
		if (!m.ast)
			continue ;
		exec_ast(&m, m.ast);
		shell_cleaner(&m);
		//system("leaks minishell");
	}
	return (EXIT_SUCCESS);
}
