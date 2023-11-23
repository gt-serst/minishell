/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:58 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/23 17:13:00 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
