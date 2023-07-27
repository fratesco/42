/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:27:06 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/27 16:45:01 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_action(t_info *info)
{
	sem_wait((info->write));
	if (info->philo.action == SLEEPING)
		printf("%llu %i is sleeping\n",
			get_time(info->start_time), info->philo.id);
	else if (info->philo.action == EATING)
		printf("%llu %i is eating\n",
			get_time(info->start_time), info->philo.id);
	else if (info->philo.action == THINKING)
		printf("%llu %i is thinking\n",
			get_time(info->start_time), info->philo.id);
	else if (info->philo.action == PICKING_FORK)
		printf("%llu %i has taken a fork\n",
			get_time(info->start_time), info->philo.id);
	sem_post((info->write));
}

void	ft_sleep(int i, t_info *info)
{
	unsigned long long int	start;

	start = get_time(info->start_time);
	while ((get_time(info->start_time) - start < i) && !is_dead(info))
		usleep(50);
}

void	parent_checker(void)
{
	int	status;

	while (waitpid(-1, &status, 0))
	{
		//printf("%p\n", status);
	}
}

int	any_dead(t_info *info)
{
	return (0);
}

void	unlocker(t_info *info, int i)
{
	while (i--)
	{
		sem_post(info->forks);
	}
}