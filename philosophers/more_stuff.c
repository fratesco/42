/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:05:43 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/06 17:35:14 by fgolino          ###   ########.fr       */
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
