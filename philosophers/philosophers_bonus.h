/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:42:08 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/20 16:14:16 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphores.h>

# define THINKING 0
# define PICKING_FORK 1
# define EATING 2
# define SLEEPING 3

typedef struct s_philo_bonus
{
	int				philo_id;
	int				action;
	int				is_dead;
	int				eat_num;
	int				last_meal;
	int				full;
	struct s_info	*info;
	sem_t			*forks;	
}	t_philo_bonus;

typedef struct s_info_bonus
{
	int							time_eat;
	int							time_death;
	int							sleep_time;
	unsigned long long int		start_time;
	int							num_philo;
	int							eat_num;
	int							philo_dead;
	t_philo						*philosophers;
	pthread_mutex_t				write_right;
	pthread_mutex_t				death_rigth;
	sem_t						forks;
}	t_info_bonus;

#endif