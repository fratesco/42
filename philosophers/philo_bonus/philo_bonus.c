/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:17:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/19 11:20:20 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_generator(int id, t_info *info, t_philo *tmp)
{
	tmp->id = id;
	tmp->action = 0;
	tmp->is_dead = 0;
	tmp->eat_num = 0;
	tmp->last_meal = 0;
	tmp->eat_max = info->eat_num;
	tmp->start = info->start_time;
	tmp->sleep_time = info->sleep_time;
	tmp->time_eat = info->time_eat;
	tmp->time_death = info->time_death;
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
			//printf("a\n");
			bonus_routine(i + 1, info);
			exit (0);
		}
	}
	while (waitpid(-1, NULL, 0))
		continue ;
}

void	bonus_routine(int id, t_info *info)
{
	t_philo		*philo;
	pthread_t	tmp;

	philo_generator(id, info, philo);
	pthread_create(&tmp, NULL, &checker_routine, (void *)philo);
	pthread_detach(tmp);
	printf("cazzi\n");
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
