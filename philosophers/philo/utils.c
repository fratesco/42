/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:36:40 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/11 17:15:47 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	freerer(t_info *info)
{
	if (info->forks)
		free(info->forks);
	if (info->philosophers)
		free(info->philosophers);
}

void	*checker_routine(void *in)
{
	t_info	*info;
	int		i;

	info = (t_info *)in;
	while (1)
	{
		i = 0;
		while (i < info->num_philo)
		{
			full_or_dead(&(info->philosophers[i]));
			i++;
		}
		if (info->philo_dead == 1 || info->full == 1)
			return (0);
	}
}

unsigned long long int	get_time(t_info *info)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000) - info->start_time);
}

void	print_action(t_info *info, t_philo *philo)
{
	if (!any_dead(info))
	{
		if (!any_dead(info))
			pthread_mutex_lock(&(philo->info->write_right));
		if (philo->action == SLEEPING && !any_dead(info))
			printf("%llu %i is sleeping\n", get_time(info), philo->philo_id);
		else if (philo->action == EATING && !any_dead(info))
			printf("%llu %i is eating\n", get_time(info), philo->philo_id);
		else if (philo->action == THINKING && !any_dead(info))
			printf("%llu %i is thinking\n", get_time(info), philo->philo_id);
		else if (philo->action == PICKING_FORK && !any_dead(info))
			printf("%llu %i has taken a fork\n",
				get_time(info), philo->philo_id);
		pthread_mutex_unlock(&(philo->info->write_right));
	}
	else
		return ;
}
