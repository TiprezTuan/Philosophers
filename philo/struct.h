/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:52:34 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/08 14:57:56 by ttiprez          ###   ########.fr       */
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

typedef struct	s_philo_settings 
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_eat_by_philo;
}	t_philo_settings;

typedef struct	s_philo
{
	int					num_philo;
	pthread_t			thread;
	int					nb_eaten;
	long				last_meal;
	t_philo_settings	*settings;
	t_fork				*left_fork;
	t_fork				*right_fork;
}	t_philo;

#endif