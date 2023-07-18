/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:17:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/18 11:47:28 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_generator(t_info *info)
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
		i++;
	}
}

void	start_processes(t_info *info)
{
	int	i;

	i = -1;
	if (!fork())
		checker_routine(info);
	while (++i < info->num_philo)
	{
		if (fork())
			continue ;
		else
		{
			bonus_routine(&(info->philosophers[i]));
			exit (0);
		}
	}
	while (waitpid(-1, NULL, 0) > 0)
		continue ;
}

void	bonus_routine(t_philo *philo)
{
	sem_t *forks = sem_open("/forks", 0);
	sem_t*write_right = sem_open("/write", 0);
	while (1)
	{
		if (sem_trywait(forks) == 0)
			printf("suca");
		lock_forks(philo);
		if (philo->info->num_philo > 1)
			philo_eater(philo);
	}
}

void	lock_forks(t_philo	*philo)
{
	ft_sleep(philo->philo_id - 1, philo);
	if (!philo->is_dead)
		sem_wait(philo->forks);
	printf("obh\n");
	philo->action = PICKING_FORK;
	print_action(philo->info, philo);
	if (!philo->is_dead)
		return (unlocker(philo, 1));
	if (philo->info->num_philo == 1)
		ft_sleep(philo->info->time_death, philo);
	if (!philo->is_dead)
		sem_wait(philo->forks);
	print_action(philo->info, philo);
	if (philo->is_dead && (philo->info->num_philo > 1))
		return (unlocker(philo, 2));
}

void	philo_eater(t_philo *philo)
{
	if (any_dead(philo->info))
		unlocker(philo, 2);
	if (philo->info->num_philo > 1)
	{
		philo->action = EATING;
		print_action(philo->info, philo);
		philo->last_meal = get_time(philo->info);
		ft_sleep((philo->info->time_eat), philo);
		sem_post(philo->forks);
		sem_post(philo->forks);
		philo->eat_num++;
	}
	if (philo->info->num_philo > 1)
	{
		philo->action = SLEEPING;
		print_action(philo->info, philo);
		ft_sleep((philo->info->sleep_time), philo);
	}
	philo->action = THINKING;
	print_action(philo->info, philo);
}
