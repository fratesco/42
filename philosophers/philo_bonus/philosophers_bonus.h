/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:42:08 by fgolino           #+#    #+#             */
/*   Updated: 2023/07/18 11:40:40 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>

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
	struct s_info	*info;
	sem_t			*forks;
	sem_t			*write_right;
}	t_philo;

typedef struct s_info
{
	int									time_eat;
	int									time_death;
	int									sleep_time;
	unsigned long long int				start_time;
	int									num_philo;
	int									eat_num;
	int									philo_dead;
	int									full;
	int									*pid;
	struct s_philo						*philosophers;
	sem_t								*write_right;
	sem_t								*forks;
}	t_info;

int						argument_handler(t_info *info, int argc, char **argv);
int						argument_checker(int argc, char **argv);
int						error_handler(int id);
void					philo_generator(t_info *info);
void					start_processes(t_info *info);
void					bonus_routine(t_philo *philo);
int						ft_atoi(const char *str);
unsigned long long int	get_time(t_info *info);
void					freerer(t_info *info);
int						is_dead(t_philo *philo);
int						all_full(t_info *info);
int						full_or_dead(t_philo *philo);
void					print_action(t_info *info, t_philo *philo);
void					ft_sleep(int i, t_philo *philo);
void					unlocker(t_philo *philo, int i);
void					*checker_routine(t_info *info);
int						any_dead(t_info *info);
void					lock_forks(t_philo	*philo);
void					philo_eater(t_philo *philo);
#endif