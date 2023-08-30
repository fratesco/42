/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:46:52 by fgolino           #+#    #+#             */
/*   Updated: 2023/08/30 17:27:33 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_info g_info;

void	interrupt(int signum)
{
	if (g_info.ins_pid != 0)
		kill(g_info.ins_pid, SIGINT);
	printf("\n");

}

void	signal_rewire(void)
{
	//qui gestisci i segnali con sigaction
}
