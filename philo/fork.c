/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:02:03 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/09 16:19:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#include "philosophers.h"
#include "struct.h"

bool	init_forks(t_fork **f, t_p_settings *p_settings)
{
	int	i;

	*f = malloc(sizeof(t_fork) * p_settings->num_of_philo);
	if (!*f)
		return (false);
	i = -1;
	while (++i < p_settings->num_of_philo)
	{
		if (pthread_mutex_init(&(*f)[i].mutex, NULL) != 0)
			return (destroy_i_mutex(NULL, 0, f, i), false);
	}
	return (true);
}

void	take_fork(t_philo *p)
{
	if (p->num_philo % 2 == 0)
	{
		pthread_mutex_lock(&p->right_fork->mutex);
		printf("%ld %d has taken a fork\n", current_time_ms(), p->num_philo);
		pthread_mutex_lock(&p->left_fork->mutex);
		printf("%ld %d has taken a fork\n", current_time_ms(), p->num_philo);
	}
	else
	{
		pthread_mutex_lock(&p->left_fork->mutex);
		printf("%ld %d has taken a fork\n", current_time_ms(), p->num_philo);
		pthread_mutex_lock(&p->right_fork->mutex);
		printf("%ld %d has taken a fork\n", current_time_ms(), p->num_philo);
	}

	pthread_mutex_lock(&p->meal_mutex);
	p->last_meal = current_time_ms();
	pthread_mutex_unlock(&p->meal_mutex);
}

void	drop_fork(t_philo *p)
{
	pthread_mutex_unlock(&p->right_fork->mutex);
	pthread_mutex_unlock(&p->left_fork->mutex);
}