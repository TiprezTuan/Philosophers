/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:21:25 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/27 15:36:31 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "philosophers.h"
#include "struct.h"

void	thinking(t_philo *p)
{
	print_status(p, current_time_ms(), "is thinking");
	smart_sleep(p->settings->time_to_eat * 2 - p->settings->time_to_sleep * 0.5,
				p->settings);
}

void	eating(t_philo *p)
{
	long	timestamp;
	bool	finished_eating;

	take_fork(p);
	timestamp = current_time_ms();
	pthread_mutex_lock(&p->meal_mutex);
	p->last_meal = timestamp;
	p->nb_eaten++;
	finished_eating = p->nb_eaten == p->settings->nb_eat_by_philo;
	pthread_mutex_unlock(&p->meal_mutex);
	print_status(p, timestamp, "is eating");
	if (finished_eating)
	{
		pthread_mutex_lock(&p->settings->nb_philo_eaten_all_mutex);
		p->settings->nb_philo_eaten_all++;
		pthread_mutex_unlock(&p->settings->nb_philo_eaten_all_mutex);
	}
	smart_sleep(p->settings->time_to_eat, p->settings);
	drop_fork(p);
}

void	sleeping(t_philo *p)
{
	print_status(p, current_time_ms(), "is sleeping");
	smart_sleep(p->settings->time_to_sleep, p->settings);
}
