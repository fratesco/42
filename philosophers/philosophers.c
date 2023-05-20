/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:25:12 by fgolino           #+#    #+#             */
/*   Updated: 2023/05/20 10:42:36 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_handler(int id)
{
	if (id == 1)
	{
		printf("Not enougth arguments!");
		return (1);
	}
	else if (id == 2)
	{
		printf("Too many arguments");
		return (1);
	}
	return (0);
}

void	argument_handler(t_info *info, int argc, char **argv)
{
	int	i;

	info->num_philo = ft_atoi(argv[1]);
	info->time_death = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		info->eat_num = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5)
		return (error_handler(1));
	else if (argc > 6)
		return (error_handler(2));
	else
		argument_handler(&info, argc, argv);
}