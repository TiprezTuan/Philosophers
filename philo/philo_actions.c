/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:21:25 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/09 17:20:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "philosophers.h"
#include "struct.h"

void	thinking(t_philo *p)
{
	print_status(p, current_time_ms(), "is thinking");
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
	print_status(p, timestamp, "is eating");
	usleep(p->settings->time_to_eat * 1000);
	drop_fork(p);
}

void	sleeping(t_philo *p)
{
	print_status(p, current_time_ms(), "is sleeping");
	usleep(p->settings->time_to_sleep * 1000);
}
