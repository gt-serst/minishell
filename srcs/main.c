/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:32 by gt-serst          #+#    #+#             */
/*   Updated: 2023/11/24 00:17:07 by geraudtsers      ###   ########.fr       */
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
		init_signals(&m);
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
		signal(SIGQUIT, sigquit_handler);
		exec_ast(&m, m.ast);
		tcsetattr(STDIN_FILENO, TCSANOW, &m.original_term);
		shell_cleaner(&m);
		ft_print_token(m.token);
		ft_print_ast(m.ast);
		ft_print_expanded_ast(m.ast);
		//system("leaks minishell");
	}
	return (EXIT_SUCCESS);
}
