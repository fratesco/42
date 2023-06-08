/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:05:43 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/08 03:44:26 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	if ((get_time(philo->info) - philo->last_meal) >= philo->info->time_death
		&& philo->info->philo_dead == 0)
	{
		philo->is_dead = 1;
		return (1);
	}
	else if (philo->info->philo_dead == 1)
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
	if (info->eat_num > -1)
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
			return (1);
	}
	return (0);
}

void	philo_thinking(t_philo *philo)
{
	philo->action = THINKING;
	pthread_mutex_lock(&(philo->info->write_right));
	if (!full_or_dead(philo))
		print_action(philo->info, philo);
	pthread_mutex_unlock(&(philo->info->write_right));
}

void	unlocker(t_philo *philo, int i)
{
	if (i == 1)
		pthread_mutex_unlock(philo->left_fork);
	else if (i == 2)
		pthread_mutex_unlock(philo->right_fork);
	else if (i == 3)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}
