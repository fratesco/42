/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:25:12 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/07 10:30:45 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_handler(int id)
{
	if (id == 1)
	{
		printf("Not enougth arguments!\n");
		return (1);
	}
	else if (id == 2)
	{
		printf("Too many arguments\n");
		return (1);
	}
	return (0);
}

int	argument_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				printf("Invalid argument\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	argument_handler(t_info *info, int argc, char **argv)
{
	int				i;
	struct timeval	t;

	info->num_philo = ft_atoi(argv[1]);
	info->time_death = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		info->eat_num = ft_atoi(argv[5]);
	else
		info->eat_num = 0;
	if (info->num_philo < 0 || info->time_death < 0 || info->time_eat < 0
		|| info->sleep_time < 0 || info->eat_num < 0)
		return (1);
	gettimeofday(&t, NULL);
	info->start_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	info->philo_dead = 0;
	pthread_mutex_init(&info->write_right, NULL);
	return (0);
}

void	fork_generator(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	while (i < info->num_philo)
		pthread_mutex_init(&(info->forks[i++]), NULL);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5)
		return (error_handler(1));
	else if (argc > 6)
		return (error_handler(2));
	else if (argument_checker(argc, argv))
		return (1);
	else if (argument_handler(&info, argc, argv))
		return (1);
	fork_generator(&info);
	philo_generator(&info);
	start_philo_thread(&info);
	freerer(&info);
	return (0);
}
