/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:24 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/13 07:21:25 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#include "philosophers.h"
#include "struct.h"

int	main(int ac, char const **av)
{
	t_p_settings		p_settings;
	t_philo				*philo;
	t_fork				*forks;

	if (ac < 5)
		return (printf("Error\n4 arguments minimum.\n"), EXIT_FAILURE);
	if (ac > 6)
		return (printf("Error\n5 arguments maximum.\n"), EXIT_FAILURE);
	p_settings = init_p_settings(ac, av);
	if (!init_forks(&forks, &p_settings)
		|| !init_philo(&philo, forks, &p_settings))
		return (free_all(NULL, forks, &p_settings),
			EXIT_FAILURE);
	if (!start_all_philo_routine(philo))
		return (free_all(philo, forks, &p_settings),
			EXIT_FAILURE);
	hypervisor(philo, &p_settings);
	join_all(philo, &p_settings);
	return (free_all(philo, forks, &p_settings), EXIT_SUCCESS);
}
