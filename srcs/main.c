/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:22:32 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/26 12:02:22 by mde-plae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{// main function, the bash cmd requested by the user is located in arguments, the function in in charge of the core routine for minishell, the following steps will be launched read, lexer, parser, expander and execution
	t_minishell	m;

	(void)argc;
	(void)argv;
	init_env(envp);
	while (1)
	{
		m.cmd_line = readline("minishell$ ");
		if (!m.cmd_line)
			ft_exit_message("Error: Command line not found\n");
		add_history(m.cmd_line);
		tokenizer(&m);
		//parser();
		//ft_exec()
	}
}
