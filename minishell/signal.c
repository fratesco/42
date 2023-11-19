/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:46:52 by fgolino           #+#    #+#             */
/*   Updated: 2023/11/19 17:45:59 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	interrupt(int signum)
{
	g_signal = signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line ("", 0);
	rl_redisplay();
}

void	quitter(int signum)
{
	//bisogna trovare un modo per non far partire questo comando quando la stringa di readline è vuota
	exit(0);
}

void	signal_rewire(void)
{
	struct sigaction	new_action;

	new_action.sa_handler = interrupt;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGINT, &new_action, NULL);
	new_action.sa_handler = quitter;
	sigemptyset(&new_action.sa_mask);
	sigaction(SIGQUIT, &new_action, NULL);
}

void	signal_fork(void)
{
	struct sigaction	new_action;	

	new_action.sa_handler = SIG_DFL;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGINT, &new_action, NULL);
	new_action.sa_handler = SIG_DFL;
	sigemptyset(&new_action.sa_mask);
	sigaction(SIGQUIT, &new_action, NULL);
}
