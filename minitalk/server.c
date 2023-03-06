/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:48:21 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/06 12:04:58 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_receive(void)
{
	ft_printf("%s", g_server);
	free(g_server);
	kill(g_client, SIGUSR2);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	set;
	struct sigaction	old_set;

	set.sa_handler = server_receive;
	sigemptyset(&set.sa_mask);
	set.sa_flags = 0;
	ft_printf("%i", g_client);
	sigaction(SIGUSR1, NULL, &old_set);
	if (old_set.sa_handler != SIG_IGN)
		sigaction(SIGUSR1, &set, NULL);
	while (1)
		pause();
	return (0);
}