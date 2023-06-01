/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:32:37 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/01 17:19:19 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define THINKING 0
# define PICKING_FORK 1
# define EATING 2
# define SLEEPING 3

typedef struct s_info
{
	int							time_eat;
	int							time_death;
	int							sleep_time;
	unsigned long long int		start_time;
	int							num_philo;
	int							eat_num;
	int							philo_dead;
	t_philo						*philosophers;
	pthread_mutex_t				*forks;
}	t_info;

typedef struct s_philo
{
	int				philo_id;
	int				action;
	int				is_dead;
	int				eat_num;
	int				last_meal;
	t_info			*info;
	pthread_t		thread_id;
	pthread_mutex_t	write_right;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;	
}	t_philo;

int		error_handler(int id);
int		ft_atoi(const char *str);
void	philo_genearator(t_info *info);
int		argument_checker(int argc, char **argv);
void	argument_handler(t_info *info, int argc, char **argv);
void	freerer(t_info *info);
void	print_action(t_info *info, t_philo *philo);
void	fork_generator(t_info *info);
#endif