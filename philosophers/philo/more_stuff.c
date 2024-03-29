/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:05:43 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/13 12:41:06 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	if ((get_time(philo->info) - ((philo->last_meal)))
		>= (philo->info->time_death) && philo->info->philo_dead == 0)
	{
		philo->info->philo_dead = 1;
		pthread_mutex_lock(&philo->info->write_right);
		printf("%llu %i died\n", get_time(philo->info), philo->philo_id);
		pthread_mutex_unlock(&philo->info->write_right);
		return (1);
	}
	if (philo->info->philo_dead == 1)
		return (1);
	else
		return (0);
}

int	full_or_dead(t_philo *philo)
{
	if (!is_dead(philo) && !all_full(philo->info) && !philo->info->philo_dead)
		return (0);
	return (1);
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

void	unlocker(t_philo *philo, int i)
{
	if (i == 1 && philo->philo_id % 2 == 0)
		pthread_mutex_unlock(philo->left_fork);
	else if (i == 1)
		pthread_mutex_unlock(philo->right_fork);
	else if (i == 2 && philo->philo_id % 2 == 0)
		pthread_mutex_unlock(philo->right_fork);
	else if (i == 2)
		pthread_mutex_unlock(philo->left_fork);
	else if (i == 3)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	ft_sleep(int i, t_philo *philo)
{
	unsigned long long int	start;

	start = get_time(philo->info);
	while ((get_time(philo->info) - start < i) && !(philo->info->full)
		&& !philo->info->philo_dead)
		usleep(50);
}
