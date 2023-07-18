/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:24:52 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/18 11:13:30 by fgolino          ###   ########.fr       */
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

unsigned long long int	get_time(t_info *info)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000) - info->start_time);
}

void	freerer(t_info *info)
{
	if (info->philosophers)
		free(info->philosophers);
	if (info->pid)
		free(info->pid);
}

int	is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	if ((get_time(philo->info) - ((philo->last_meal)))
		>= (philo->info->time_death) && philo->info->philo_dead == 0)
	{
		philo->info->philo_dead = 1;
		sem_wait(philo->write_right);
		printf("%llu %i died\n", get_time(philo->info), philo->philo_id);
		//while (i < philo->info->num_philo)
		//	kill(philo->info->pid[i], SIGTERM);
		sem_post(philo->write_right);
		exit(0);
	}
	if (philo->info->philo_dead == 1)
		return (1);
	else
		return (0);
}

int	all_full(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (info->full == 1)
		return (1);
	if (info->eat_num > 0)
	{
		while (i < info->num_philo)
		{
			if (info->philosophers[i].eat_num >= info->eat_num)
				j++;
			else
				return (0);
			i++;
		}
		if (j == info->num_philo)
		{
			info->full = 1;
			return (1);
		}
	}
	return (0);
}
