/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:52:34 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/09 16:08:42 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <pthread.h>
#include <stdbool.h>

typedef struct	s_fork
{
	pthread_mutex_t		mutex;
}	t_fork;

typedef struct	s_p_settings 
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat_by_philo;
	int				nb_philo_eaten_all;
	pthread_mutex_t	philo_died_mutex;
	int				philo_died;
}	t_p_settings;

typedef struct	s_philo
{
	int				num_philo;
	pthread_t		thread;
	int				nb_eaten;
	long			last_meal;
	pthread_mutex_t	meal_mutex;
	t_p_settings	*settings;
	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philo;

#endif