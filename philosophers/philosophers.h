/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <fgolino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:32:37 by fgolino           #+#    #+#             */
/*   Updated: 2023/05/20 10:44:20 by fgolino          ###   ########.fr       */
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
	int	time_eat;
	int	time_death;
	int	sleep_time;
	int	num_philo;
	int	eat_num;
}	t_info;

typedef struct s_philo
{
	int	philo_id;
	int	is_dead;
	int	eat_num;
}	t_philo;

int		error_handler(int id);
int		ft_atoi(const char *str);
#endif