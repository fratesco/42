/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:27:06 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/18 10:02:05 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_action(t_info *info, t_philo *philo)
{
	{
		sem_wait((philo->write_right));
		if (philo->action == SLEEPING)
			printf("%llu %i is sleeping\n", get_time(info), philo->philo_id);
		else if (philo->action == EATING)
			printf("%llu %i is eating\n", get_time(info), philo->philo_id);
		else if (philo->action == THINKING)
			printf("%llu %i is thinking\n", get_time(info), philo->philo_id);
		else if (philo->action == PICKING_FORK)
			printf("%llu %i has taken a fork\n",
				get_time(info), philo->philo_id);
		sem_post((philo->write_right));
	}
}

void	ft_sleep(int i, t_philo *philo)
{
	unsigned long long int	start;

	start = get_time(philo->info);
	while ((get_time(philo->info) - start < i)
		&& !philo->is_dead)
		usleep(50);
}

void	*checker_routine(t_info *info)
{
	int		i;

	info->write_right = sem_open("/write", 0);
	while (1)
	{
		i = 0;
		while (i < info->num_philo)
			full_or_dead(&(info->philosophers[i++]));
		if (info->philo_dead == 1 || info->full == 1)
			exit (0);
	}
	exit (0);
}

int	any_dead(t_info *info)
{
	if (info->philo_dead)
		return (1);
	if (info->full)
		return (1);
	return (0);
}

void	unlocker(t_philo *philo, int i)
{
	while (i--)
	{
		sem_post(philo->forks);
	}
}