/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:58:21 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/01 17:16:51 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_genearator(t_info *info)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	info->philosophers = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	while (i < info->num_philo)
	{
		info->philosophers[i].philo_id = 1 + i;
		info->philosophers[i].action = 0;
		info->philosophers[i].is_dead = 0;
		info->philosophers[i].eat_num = 0;
		info->philosophers[i].last_meal = 0;
		info->philosophers[i].info = info;
		info->philosophers[i].left_fork = &(info->fork[i]);
		info->philosophers[i].right_fork = &(info->fork[(i + 1) % info->num_philo];
	}
}

void	start_philo_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
		pthread_create(info->philosophers[i].id, NULL, &philo_routine, (void *)info->philosophers[i++]);
	
	
}
