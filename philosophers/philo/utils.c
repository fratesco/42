/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:36:40 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/19 17:45:13 by fgolino          ###   ########.fr       */
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

void	*philo_death(t_philo *philo)
{
	if (philo->info->philo_dead == 0)
		print_action(philo->info, philo);
	return (0);
}

unsigned long long int	get_time(t_info *info)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000) - info->start_time);
}

void	print_action(t_info *info, t_philo *philo)
{
	if (!philo->info->philo_dead && !all_full(philo->info))
	{
		if (philo->is_dead && !philo->info->philo_dead)
		{
			if (pthread_mutex_trylock(&(philo->info->death_right)))
				return ;
			philo->info->philo_dead = 1;
			pthread_mutex_lock(&(philo->info->write_right));
			printf("%llu %i died\n", get_time(info), philo->philo_id);
		}
		if (!philo->info->philo_dead)
			pthread_mutex_lock(&(philo->info->write_right));
		if (philo->action == SLEEPING && !full_or_dead(philo))
			printf("%llu %i is sleeping\n", get_time(info), philo->philo_id);
		else if (philo->action == EATING && !full_or_dead(philo))
			printf("%llu %i is eating\n", get_time(info), philo->philo_id);
		else if (philo->action == THINKING && !full_or_dead(philo))
			printf("%llu %i is thinking\n", get_time(info), philo->philo_id);
		else if (philo->action == PICKING_FORK && !full_or_dead(philo))
			printf("%llu %i has taken a fork\n",
				get_time(info), philo->philo_id);
		pthread_mutex_unlock(&(philo->info->write_right));
	}
	else
		return ;
}
