/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:24:52 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/27 23:43:31 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (sign % 2 == 0)
		return (num);
	return (-num);
}

unsigned long long int	get_time(unsigned long long int start)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000) - start);
}

int	is_dead(t_info *info)
{
	int	i;

	i = 0;
	if ((get_time(info->start_time) - ((info->philo.last_meal)))
		>= (info->time_death))
	{
		info->philo.is_dead = 1;
		sem_wait(info->write);
		printf("%llu %i died\n", get_time(info->start_time), info->philo.id);
		kill(0, SIGKILL);
		exit(0);
	}
	else
		return (0);
}
