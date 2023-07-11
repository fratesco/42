/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:17:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/11 16:21:06 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_generator(t_info_bonus *info)
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
		info->philosophers[i].forks = &(info->forks);
		i++;
	}
}

void	start_processes(t_info *info)
{
	int	i;

	i = -1;
	while (i++ < info->num_philo - 1)
	{
		if (fork())
			continue ;
		bonus_routine(&(info->philosophers[i]));
	}
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
}

void	bonus_routine(t_philo *philo)
{
	while (1)
	{
		if (philo->info->philo_dead == 1 && philo->is_dead == 0)
			return (0);
		else if (philo->is_dead == 1 && philo->info->philo_dead == 0)
			return (philo_death(philo));
		if (all_full(philo->info))
			return (0);
		if ((get_time(philo->info) - philo->last_meal)
			>= philo->info->time_death)
		{
			philo->is_dead = 1;
			continue ;
		}
		if (!(philo->info->philo_dead == 1) && philo->is_dead == 0)
			lock_forks(philo);
		if (philo->right_fork != 0)
			philo_eater(philo);
		if (philo->info->philo_dead && philo->is_dead)
			return (0);
	}
}

void	lock_forks(t_philo	*philo)
{
	ft_sleep(philo->philo_id - 1, philo);
	if (!full_or_dead(philo))
		sem_wait(philo->forks);
	philo->action = PICKING_FORK;
	print_action(philo->info, philo);
	if (full_or_dead(philo))
		return (unlocker(philo, 1));
	if (philo->right_fork == 0)
		ft_sleep(philo->info->time_death, philo);
	while (!full_or_dead(philo) && philo->right_fork != 0)
	{
		if (pthread_mutex_trylock(philo->right_fork))
			continue ;
		break ;
	}
	print_action(philo->info, philo);
	if (full_or_dead(philo) && philo->right_fork != 0)
		return (unlocker(philo, 3));
}
