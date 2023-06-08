/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:32:37 by fgolino           #+#    #+#             */
/*   Updated: 2023/06/08 06:15:17 by fgolino          ###   ########.fr       */
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

typedef struct s_philo
{
	int				philo_id;
	int				action;
	int				is_dead;
	int				eat_num;
	int				last_meal;
	int				full;
	struct s_info	*info;
	pthread_t		thread_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;	
}	t_philo;

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
	pthread_mutex_t				write_right;
	pthread_mutex_t				*forks;
}	t_info;

int						error_handler(int id);
int						ft_atoi(const char *str);
void					philo_generator(t_info *info);
int						argument_checker(int argc, char **argv);
int						argument_handler(t_info *info, int argc, char **argv);
void					freerer(t_info *info);
void					print_action(t_info *info, t_philo *philo);
void					fork_generator(t_info *info);
void					start_philo_thread(t_info *info);
void					*philo_death(t_philo *philo);
int						is_dead(t_philo *philo);
void					philo_eater(t_philo *philo);
void					lock_forks(t_philo	*philo);
void					*philo_routine(void *plato);
unsigned long long int	get_time(t_info *info);
int						full_or_dead(t_philo *philo);
int						all_full(t_info *info);
void					philo_thinking(t_philo *philo);
void					unlocker(t_philo *philo, int i);
void					ft_sleep(int i, t_philo *philo);
#endif