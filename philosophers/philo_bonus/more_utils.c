/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:27:06 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/11 16:10:04 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_action(t_philo *philo)
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

void	ft_sleep(int i, t_philo *philo)
{
	unsigned long long int	start;

	start = get_time(philo->info);
	while ((get_time(philo->info) - start < i) && !full_or_dead(philo))
		usleep(50);
}