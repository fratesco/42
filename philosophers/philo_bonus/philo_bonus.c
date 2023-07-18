/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:17:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/18 15:36:16 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_generator(int id, unsigned long long int start_time, int eat, t_philo *tmp)
{
	tmp->id = id;
	tmp->action = 0;
	tmp->is_dead = 0;
	tmp->eat_num = 0;
	tmp->last_meal = 0;
	tmp->eat_max = eat;
	tmp->start = start_time;
	tmp->write_right = sem_open("/write", 0);
	tmp->forks = sem_open("/forks", 0);
}

void	start_processes(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		info->pid[i] = fork();
		if (info->pid[i])
			continue ;
		else
		{
			bonus_routine(i, info->start_time, info->eat_num);
			exit (0);
		}
	}
	while (waitpid(-1, NULL, 0));
}

void	bonus_routine(int id, unsigned long long int start, int eat)
{
	t_philo		*philo;
	pthread_t	tmp;

	philo_generator(id, start, eat, philo);
	pthread_create(&tmp, NULL, &checker_routine, (void *)philo);
	pthread_detach(tmp);
	while (1)
	{
		lock_forks(philo);
		philo_eater(philo);
	}
}

void	lock_forks(t_philo	*philo)
{
	ft_sleep(philo->id - 1, philo);
	sem_wait(philo->forks);
	philo->action = PICKING_FORK;
	print_action(philo);
	sem_wait(philo->forks);
	print_action(philo);
}

void	philo_eater(t_philo *philo)
{
	philo->action = EATING;
	print_action(philo);
	philo->last_meal = get_time(philo->start);
	ft_sleep((philo->time_eat), philo);
	sem_post(philo->forks);
	sem_post(philo->forks);
	philo->eat_num++;
	philo->action = SLEEPING;
	print_action(philo);
	ft_sleep((philo->sleep_time), philo);
	philo->action = THINKING;
	print_action(philo);
}
