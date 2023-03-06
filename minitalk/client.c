/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:35:13 by fgolino           #+#    #+#             */
/*   Updated: 2023/03/06 13:48:37 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



void	client_receive(int sign)
{

}

int	client_send(char *str, int pid)
{
	
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	set;
	struct sigaction	old_set;

	set.sa_handler = client_receive;
	sigemptyset(&set.sa_mask);
	set.sa_flags = 0;
	sigaction(SIGUSR2, NULL, &old_set);
	if (old_set.sa_handler != SIG_IGN)
		sigaction(SIGUSR2, &set, NULL);
	g_client = getpid();
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
