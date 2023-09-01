/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:46:52 by fgolino           #+#    #+#             */
/*   Updated: 2023/09/01 21:54:04 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info	g_info;

void	interrupt(int signum)
{
	if (g_info.ins_pid != 0)
		kill(g_info.ins_pid, SIGINT);
	printf("\n");
	//forse va aggiunto un readline anche qui

}

void	signal_rewire(void)
{
	struct sigaction	new_action;
	//qui gestisci i segnali con sigaction
	new_action.sa_handler = interrupt;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGINT, &new_action, NULL);
}
