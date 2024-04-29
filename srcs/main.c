/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:32 by gt-serst          #+#    #+#             */
/*   Updated: 2024/04/29 14:38:37 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell	m;

	((void)argc, (void)argv);
	init_env(&m, envp);
	while (1)
	{
		init_signals(&m);
		m.cmd_line = readline("~>");
		if (!m.cmd_line)
			(shell_cleaner(&m),
				ft_putstr_fd("exit\n", 1), exit(E_CMD_NOT_FOUND));
		if (m.cmd_line[0])
			add_history(m.cmd_line);
		m.token = tokenizer(&m);
		if (!m.token)
			continue ;
		m.ast = parser(&m);
		if (!m.ast)
			continue ;
		signal(SIGQUIT, sigquit_handler);
		m.err_code = exec_ast(&m, m.ast);
		tcsetattr(STDIN_FILENO, TCSANOW, &m.original_term);
		shell_cleaner(&m);
	}
	return (EXIT_SUCCESS);
}
// main function, the bash cmd requested
// by the user is located in arguments,
// the function in in charge of the core routine for minishell,
// the following steps will be launched:
// read, lexer, parser, expander and execution
