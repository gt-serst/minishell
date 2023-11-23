/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:58 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/23 23:01:39 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	sigint_handler(int num)
{
	(void)num;
	if (g_signint)
	{
		ft_putstr_fd("\n", 1);
		g_signint = 0;
	}
	else
	{
		ft_putstr_fd("\n", 1);
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}

void	init_signals(t_minishell *m)
{
	struct termios	term;

	term = m->original_term;
	term.c_lflag &= ~ECHOCTL; // to avoid print crtl + c to the prompt
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	g_signint = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
