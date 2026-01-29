/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hypervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:07:38 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/29 14:13:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "philosophers.h"
#include "struct.h"

static void	check_total_meal(t_philo *p, t_p_settings *p_settings)
{
	pthread_mutex_lock(&p_settings->nb_philo_eaten_all_mutex);
	if (p_settings->nb_philo_eaten_all == p_settings->num_of_philo)
	{
		pthread_mutex_lock(&p_settings->philo_eat_all_mutex);
		p_settings->philo_eat_all = true;
		pthread_mutex_unlock(&p_settings->philo_eat_all_mutex);
	}
	pthread_mutex_unlock(&p->settings->nb_philo_eaten_all_mutex);
}

static void	check_death(t_philo *p, t_p_settings *p_set, long timestamp)
{
	pthread_mutex_lock(&p->meal_mutex);
	if (timestamp - p->last_meal >= p_set->time_to_die)
	{
		print_status(p, "died");
		pthread_mutex_lock(&p_set->philo_died_mutex);
		p_set->philo_died = p->num_philo;
		pthread_mutex_unlock(&p_set->philo_died_mutex);
	}
	pthread_mutex_unlock(&p->meal_mutex);
}

void	hypervisor(t_philo *p, t_p_settings *p_settings)
{
	int		i;
	long	current_timestamp;

	while (!is_simulation_over(p_settings))
	{
		i = 0;
		while (i < p_settings->num_of_philo && !is_simulation_over(p_settings))
		{
			current_timestamp = current_time_ms();
			check_death(&p[i], p->settings, current_timestamp);
			check_total_meal(&p[i], p->settings);
			i++;
		}
		usleep(1000);
	}
}

void	join_all(t_philo *p, t_p_settings *p_settings)
{
	int	i;

	i = -1;
	while (++i < p_settings->num_of_philo)
		pthread_join(p[i].thread, NULL);
}

void	smart_sleep(long sleep_time, t_p_settings *p_settings)
{
	long	start_time;

	start_time = current_time_ms();
	while (current_time_ms() - start_time < sleep_time)
	{
		if (is_simulation_over(p_settings))
			break ;
		usleep(1000);
	}
}
