/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:48:21 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/06 18:11:49 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long	g_receiver;

void	server_receive2(int sign)
{
	g_receiver = g_receiver >> 1;
	g_receiver += 0;
	ft_printf("%i\n", g_receiver);
}

void	server_receive1(int sign)
{
	g_receiver = g_receiver >> 1;
	ft_printf("%i\n", g_receiver);
	g_receiver += 2147483647;
	ft_printf("%i\n", g_receiver);

}

void	get_stuff(void)
{
	int		i;
	pid_t	pid;
	int		check;

	i = 0;
	while (i++ < 32)
		pause();
	pid = (-1 * g_receiver) - 3;
	ft_printf("This is the pid %i\n", pid);
	kill(pid, SIGUSR2);
	g_receiver = 0;
	i = 0;
	while (i++ < 32)
		pause();
	if (g_receiver == 0)
		kill(pid, SIGUSR1);
	else
		ft_printf("%c", g_receiver);
}
int	main(void)
{
	struct sigaction	set;
	struct sigaction	old_set;

	set.sa_handler = server_receive1;
	sigemptyset(&set.sa_mask);
	set.sa_flags = 0;
	sigaction(SIGUSR1, NULL, &old_set);
	if (old_set.sa_handler != SIG_IGN)
		sigaction(SIGUSR1, &set, NULL);
	set.sa_handler = server_receive2;
	sigemptyset(&set.sa_mask);
	sigaction(SIGUSR2, NULL, &old_set);
	if (old_set.sa_handler != SIG_IGN)
		sigaction(SIGUSR2, &set, NULL);
	ft_printf("%i\n", getpid());
	while (1)
	{	
		get_stuff();
	}
	return (0);
}
