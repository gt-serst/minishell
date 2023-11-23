/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:58 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/23 17:25:44 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
void	handle_sigint(int signum)
{
	(void)signum;
	g_signint = 1;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int signum)
{
	(void)signum;
}

void	signal_handlers(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
}

*/

static void	ft_sigint_handler(int num)
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
		rl_replace_line("", 0);
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
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
