/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:05:43 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/07 10:46:43 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	if ((get_time(philo->info) - philo->last_meal) >= philo->info->time_death
		&& philo->info->philo_dead == 0)
	{
		philo->is_dead = 1;
		philo->info->philo_dead = 1;
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
			return (1);
	}
	return (0);
}
