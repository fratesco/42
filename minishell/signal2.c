/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:12:58 by fgolino           #+#    #+#             */
/*   Updated: 2023/12/15 15:13:00 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	int_child_alive(int signum)
{
	g_signal = signum;
}

void	signal_avoid(void)
{
	struct sigaction	new_action;

	new_action.sa_handler = int_child_alive;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = SA_RESTART;
	sigaction(SIGINT, &new_action, NULL);
}

void	tmp_error(t_info *info, char *tmp)
{
	if (info->is_error == 0)
		info->is_error = errno;
	if (!info->str_error)
		info->str_error = strdup(tmp);
}
