/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:21:25 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/09 16:14:49 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "philosophers.h"
#include "struct.h"

void	thinking(t_philo *p)
{
	printf("%ld %d is thinking\n", current_time_ms(),
		p->num_philo);
	
}

void	eating(t_philo *p)
{
	long	timestamp;

	take_fork(p);
	timestamp = current_time_ms();
	pthread_mutex_lock(&p->meal_mutex);
	p->last_meal = timestamp;
	if (++p->nb_eaten == p->settings->nb_eat_by_philo)
		p->settings->nb_philo_eaten_all++;
	pthread_mutex_unlock(&p->meal_mutex);
	printf("%ld %d is eating\n", timestamp, p->num_philo);
	usleep(p->settings->time_to_eat);
	drop_fork(p);
}

void	sleeping(t_philo *p)
{
	printf("%ld %d is sleeping\n", current_time_ms(),
		p->num_philo);
	usleep(p->settings->time_to_sleep);
}
