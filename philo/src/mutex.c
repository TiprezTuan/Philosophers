/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:17:21 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/29 18:25:31 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philosophers.h"
#include "struct.h"

void	init_mutex(t_p_settings *p_settings)
{
	if (pthread_mutex_init(&p_settings->nb_philo_eaten_all_mutex, NULL) != 0)
		exit(EXIT_FAILURE);
	if (pthread_mutex_init(&p_settings->philo_died_mutex, NULL) != 0)
		destroy_and_exit(EXIT_FAILURE, 1, p_settings->nb_philo_eaten_all_mutex);
	if (pthread_mutex_init(&p_settings->philo_eat_all_mutex, NULL) != 0)
		destroy_and_exit(EXIT_FAILURE, 2, p_settings->nb_philo_eaten_all_mutex,
			p_settings->philo_died_mutex);
	if (pthread_mutex_init(&p_settings->print_mutex, NULL) != 0)
		destroy_and_exit(EXIT_FAILURE, 3, p_settings->nb_philo_eaten_all_mutex,
			p_settings->philo_died_mutex, p_settings->philo_eat_all_mutex);
}
