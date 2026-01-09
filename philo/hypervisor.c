/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hypervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:07:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/09 16:28:29 by ttiprez          ###   ########.fr       */
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
			if (p_settings->nb_philo_eaten_all == p_settings->nb_eat_by_philo)
			{
				printf("All philosophers eat the required number of meals.\n");
				return ;
			}
			pthread_mutex_lock(&p[i].meal_mutex);
			if (timestamp - p[i].last_meal >= p_settings->time_to_die)
			{
				printf("%ld %d died\n", timestamp, p[i].num_philo);
				pthread_mutex_lock(&p_settings->philo_died_mutex);
				p_settings->philo_died = p[i].num_philo;
				pthread_mutex_unlock(&p_settings->philo_died_mutex);
			}
			pthread_mutex_unlock(&p[i].meal_mutex);
		}
		usleep(10000);
	}
}
