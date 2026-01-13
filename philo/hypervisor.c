/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hypervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:07:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/13 08:12:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "philosophers.h"
#include "struct.h"

void	join_all(t_philo *p, t_p_settings *p_settings)
{
	int	i;

	i = -1;
	while (++i < p_settings->num_of_philo)
		pthread_join(p[i].thread, NULL);
}

void	hypervisor(t_philo *p, t_p_settings *p_settings)
{
	int		i;
	long	timestamp;

	while (!p_settings->philo_died)
	{
		i = -1;
		while (++i < p_settings->num_of_philo)
		{
			timestamp = current_time_ms();
			pthread_mutex_lock(&p_settings->nb_philo_eaten_all_mutex);
			if (p_settings->nb_philo_eaten_all == p_settings->num_of_philo)
			{
				print_status(&p[i], timestamp, "eaten his last meal");
				p_settings->philo_eat_all = true;
				pthread_mutex_unlock(&p_settings->nb_philo_eaten_all_mutex);
				return ;
			}
			pthread_mutex_unlock(&p->settings->nb_philo_eaten_all_mutex);

			pthread_mutex_lock(&p[i].meal_mutex);
			if (timestamp - p[i].last_meal >= p_settings->time_to_die)
			{
				print_status(&p[i], timestamp, "died");
				pthread_mutex_lock(&p_settings->philo_died_mutex);
				p_settings->philo_died = p[i].num_philo;
				pthread_mutex_unlock(&p_settings->philo_died_mutex);
			}
			pthread_mutex_unlock(&p[i].meal_mutex);
		}
		usleep(10000);
	}
}
