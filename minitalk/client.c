/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:35:13 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/06 18:18:56 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_client;

void	bit_sender(int unit, int pid)
{
	int	bit;
	int	i;

	i = 0;
	while (i++ < 32)
	{
		bit = (unit & 1);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		unit = unit >> 1;
	}
}

void	client_receive_continue(int sign)
{
	g_client += 1;
	g_client = g_client << 1;
}

void	client_receive_stop(int sign)
{
	g_client += 1;
	g_client = g_client << 1;
}

int	client_send(char *str, int pid)
{
	int	client_pid;
	int	i;

	i = 0;
	client_pid = getpid();
	ft_printf("%i\n", client_pid);
	bit_sender(client_pid, pid);
	pause();
	usleep(100);
	while (str[i])
	{
		bit_sender(str[i++], pid);
		ft_printf("\n");
		if (g_client == 0)
			ft_printf("An error occured");
		else
			g_client = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	set;
	struct sigaction	old_set;

	set.sa_handler = client_receive_continue;
	sigemptyset(&set.sa_mask);
	set.sa_flags = 0;
	sigaction(SIGUSR2, NULL, &old_set);
	if (old_set.sa_handler != SIG_IGN)
		sigaction(SIGUSR2, &set, NULL);
	if (argc < 2)
		return (0);
	pid = ft_atoi(argv[1]);
	if (argc < 3)
		ft_printf("No input parameter found, exiting");
	else if (argc > 3)
		ft_printf("Too many arguments");
	else
	{
		if (client_send(argv[2], pid) < 0)
			ft_printf("An error has occured, closing client");
		pause();
	}
	return (0);
}
