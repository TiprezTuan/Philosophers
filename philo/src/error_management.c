/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:04:08 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/27 13:48:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <stdarg.h>

#include "struct.h"

void	destroy_i_mutex(t_philo **p, int i_p, t_fork **f, int i_f)
{
	if (*p)
	{
		while (--i_p >= 0)
			pthread_mutex_destroy(&(*p)[i_p].meal_mutex);
		free(*p);
	}
	if (*f)
	{
		while (--i_f >= 0)
			pthread_mutex_destroy(&(*f)[i_f].mutex);
		free(*f);
	}
}

void	free_all(t_philo *p, t_fork *f, t_p_settings *p_settings)
{
	int	i;

	if (f)
	{
		i = -1;
		while (++i < p_settings->num_of_philo)
			pthread_mutex_destroy(&f[i].mutex);
		free(f);
	}
	if (p)
	{
		i = -1;
		while (++i < p_settings->num_of_philo)
			pthread_mutex_destroy(&p[i].meal_mutex);
		free(p);
	}
	pthread_mutex_destroy(&p_settings->nb_philo_eaten_all_mutex);
	pthread_mutex_destroy(&p_settings->philo_died_mutex);
	pthread_mutex_destroy(&p_settings->philo_eat_all_mutex);
	pthread_mutex_destroy(&p_settings->print_mutex);
}

void	destroy_and_exit(int exit_code, int nb_mutex, ...)
{
	pthread_mutex_t	*current_mutex;
	va_list			all_mutex;
	int				i;

	va_start(all_mutex, nb_mutex);
	i = -1;
	while (++i < nb_mutex)
	{
		current_mutex = va_arg(all_mutex, pthread_mutex_t *);
		pthread_mutex_destroy(current_mutex);
	}
	va_end(all_mutex);
	exit(exit_code);
}
