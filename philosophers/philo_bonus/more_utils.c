/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:27:06 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/18 15:29:21 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_action(t_philo *philo)
{
	{
		sem_wait((philo->write_right));
		if (philo->action == SLEEPING)
			printf("%llu %i is sleeping\n", get_time(philo->start), philo->id);
		else if (philo->action == EATING)
			printf("%llu %i is eating\n", get_time(philo->start), philo->id);
		else if (philo->action == THINKING)
			printf("%llu %i is thinking\n", get_time(philo->start), philo->id);
		else if (philo->action == PICKING_FORK)
			printf("%llu %i has taken a fork\n",
				get_time(philo->start), philo->id);
		sem_post((philo->write_right));
	}
}

void	ft_sleep(int i, t_philo *philo)
{
	unsigned long long int	start;

	start = get_time(philo->start);
	while ((get_time(philo->start) - start < i))
		usleep(50);
}

void	*checker_routine(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		full_or_dead(philo);
	}
	exit (0);
}

int	any_dead(t_info *info)
{

}

void	unlocker(t_philo *philo, int i)
{
	while (i--)
	{
		sem_post(philo->forks);
	}
}