/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:17:49 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/26 18:13:56 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_generator(t_info *info)
{
	info->philo.action = 0;
	info->philo.eat_num = 0;
	info->philo.is_dead = 0;
	info->philo.last_meal = 0;
}

void	parent_checker()
{
	
}

void	start_processes(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		info->pid = fork();
		if (!info->pid)
		{
			info->philo.id = i + 1;
			break ;
		}
	}
	if (!info->pid)
	{
		bonus_routine(info);
		exit (0);
	}
	//parent_checker(info);
	while (waitpid(-1, NULL, 0))
		continue ;
}

void	bonus_routine(t_info *info)
{
	philo_generator(info);
	while (1)
	{
		lock_forks(info);
		philo_eater(info);
	}
}

void	lock_forks(t_info *info)
{
	ft_sleep(info->philo.id - 1, info);
	sem_wait(info->forks);
	info->philo.action = PICKING_FORK;
	print_action(info);
	sem_wait(info->forks);
	print_action(info);
}

void	philo_eater(t_info *info)
{
	info->philo.action = EATING;
	print_action(info);
	info->philo.last_meal = get_time(info->start_time);
	ft_sleep((info->time_eat), info);
	//sem_post(info->forks);
	//sem_post(info->forks);
	info->philo.eat_num++;
	info->philo.action = SLEEPING;
	print_action(info);
	ft_sleep((info->sleep_time), info);
	info->philo.action = THINKING;
	print_action(info);
}
