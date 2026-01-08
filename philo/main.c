/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:00:24 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/08 18:19:35 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#include "philosophers.h"
#include "struct.h"

t_philo_settings	init_p_settings(int ac, char const **av)
{
	t_philo_settings	p_settings;

	p_settings.num_of_philo = ft_atoi(av[1]);
	p_settings.time_to_die = ft_atoi(av[2]);
	p_settings.time_to_eat = ft_atoi(av[3]);
	p_settings.time_to_sleep = ft_atoi(av[4]);
	p_settings.nb_eat_by_philo = -1;
	if (ac == 6)
		p_settings.nb_eat_by_philo = ft_atoi(av[5]);
	return (p_settings);
}

bool	init_forks(t_fork **forks, t_philo_settings *p_settings)
{
	int	i;

	*forks = malloc(sizeof(t_fork) * p_settings->num_of_philo);
	if (!*forks)
		return (false);
	i = -1;
	while (++i < p_settings->num_of_philo)
		pthread_mutex_init(&(*forks)[i].mutex, NULL);
	return (true);
}

bool	init_philo(t_philo **philo, t_fork *f, t_philo_settings *p_settings)
{
	int		i;
	int		n;
	n = p_settings->num_of_philo;
	*philo = malloc(sizeof(t_philo) * n);
	if (!*philo)
		return (false);
	i = -1;
	while (++i < n)
	{
		(*philo)[i].num_philo = i;
		(*philo)[i].thread = 0;
		(*philo)[i].nb_eaten = 0;
		(*philo)[i].last_meal = current_time_ms();
		(*philo)[i].right_fork = &f[i];
		(*philo)[i].settings = p_settings;
	}
	i = -1;
	while (++i < n)
		(*philo)[i].left_fork = &f[(i + n - 1) % n];
	return (true);
}

void	free_all(t_philo *philo, t_fork *forks, int nb_philo)
{
	int	i;

	if (forks)
	{
		i = -1;
		while (++i < nb_philo)
			pthread_mutex_destroy(&forks[i].mutex);
		free(forks);
	}
	if (philo)
		free(philo);
}

int	main(int ac, char const **av)
{	
	t_philo_settings	p_settings;
	t_philo				*philo;
	t_fork				*forks;

	if (ac < 5)
		return (printf("Error\n4 arguments minimum.\n"), EXIT_FAILURE);
	if (ac > 6)
		return (printf("Error\n5 arguments maximum.\n", EXIT_FAILURE));
	p_settings = init_p_settings(ac, av);
	if (!init_forks(&forks, &p_settings))
		return (EXIT_FAILURE);
	if (!init_philo(&philo, forks, &p_settings))
		return (free_all(NULL, forks, p_settings.num_of_philo), EXIT_FAILURE);
	free_all(philo, forks, philo->settings->num_of_philo);
	return (EXIT_SUCCESS);
}
