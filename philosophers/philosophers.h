/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:32:37 by fgolino           #+#    #+#             */
/*   Updated: 2023/05/20 13:32:25 by fgolino          ###   ########.fr       */
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

typedef struct s_info
{
	int				time_eat;
	int				time_death;
	int				sleep_time;
	int				start_time;
	int				num_philo;
	int				eat_num;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct s_philo
{
	int				philo_id;
	int				action;
	int				is_dead;
	int				eat_num;
	int				last_meal;
	t_info			*info;
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
#endif