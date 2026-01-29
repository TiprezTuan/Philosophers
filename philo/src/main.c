/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:24 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/29 14:05:21 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#include "philosophers.h"
#include "struct.h"

static bool	are_valid_args(int ac, const char **av)
{
	if (ac < 5)
		return (printf("Error\n4 arguments minimum.\n"), false);
	if (ac > 6)
		return (printf("Error\n5 arguments maximum.\n"), false);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (printf("Error\nOnly strictly positive values are allowed.\n"),
			false);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (printf("Error\nOnly strictly positive values are allowed.\n"),
			false);
	if (ft_atoi(av[1]) == 1)
	{
		usleep(ft_atoi(av[2]) * 1000);
		printf("%d 1 died\n", ft_atoi(av[2]));
		return (false);
	}
	return (true);
}

int	main(int ac, char const **av)
{
	t_p_settings		p_settings;
	t_philo				*philo;
	t_fork				*forks;

	if (!are_valid_args(ac, av))
		return (EXIT_FAILURE);
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
