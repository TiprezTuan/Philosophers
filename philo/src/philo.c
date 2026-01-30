/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:02:58 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/30 14:20:06 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "struct.h"
#include "philosophers.h"

t_p_settings	init_p_settings(int ac, char const **av)
{
	t_p_settings	p_settings;

	p_settings.start_timestamp = current_time_ms();
	p_settings.num_of_philo = ft_atoi(av[1]);
	p_settings.time_to_die = ft_atoi(av[2]);
	p_settings.time_to_eat = ft_atoi(av[3]);
	p_settings.time_to_sleep = ft_atoi(av[4]);
	p_settings.nb_eat_by_philo = -1;
	p_settings.nb_philo_eaten_all = 0;
	p_settings.philo_died = 0;
	p_settings.philo_eat_all = false;
	p_settings.start_routine = false;
	init_mutex(&p_settings);
	if (ac == 6)
		p_settings.nb_eat_by_philo = ft_atoi(av[5]);
	return (p_settings);
}

bool	init_philo(t_philo **philo, t_fork *f, t_p_settings *p_settings)
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
		(*philo)[i].num_philo = i + 1;
		(*philo)[i].thread = 0;
		(*philo)[i].nb_eaten = 0;
		(*philo)[i].last_meal = current_time_ms();
		if (pthread_mutex_init(&(*philo)[i].meal_mutex, NULL) != 0)
			return (destroy_i_mutex(philo, i, NULL, 0), false);
		(*philo)[i].right_fork = &f[i];
		(*philo)[i].settings = p_settings;
	}
	i = -1;
	while (++i < n)
		(*philo)[i].left_fork = &f[(i + n - 1) % n];
	return (true);
}

static void	*routine_three_philo(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->num_philo == 2)
		smart_sleep(p->settings->time_to_eat, p->settings);
	else if (p->num_philo == 3)
		smart_sleep(p->settings->time_to_eat * 1.5, p->settings);
	while (!is_simulation_over(p->settings))
	{
		eating(p);
		sleeping(p);
		thinking(p);
	}
	return (NULL);
}

static void	*routine_philo(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->settings->num_of_philo % 2 != 0)
	{
		if (p->num_philo == 2)
			smart_sleep(p->settings->time_to_eat * 1.5, p->settings);
		else if (p->num_philo == 3)
			smart_sleep(p->settings->time_to_eat * 0.5, p->settings);
		else if (p->num_philo % 2 == 0)
			smart_sleep(p->settings->time_to_eat * 2, p->settings);
		else if (p->num_philo != 1)
			smart_sleep(p->settings->time_to_eat, p->settings);
	}
	else if (p->num_philo % 2 == 0)
		smart_sleep(p->settings->time_to_eat / 2, p->settings);
	while (!is_simulation_over(p->settings))
	{
		eating(p);
		sleeping(p);
		thinking(p);
	}
	return (NULL);
}

bool	start_all_philo_routine(t_philo *p)
{
	int		i;

	i = -1;
	if (p->settings->num_of_philo != 3)
	{
		while (++i < p->settings->num_of_philo)
			if (pthread_create(&p[i].thread, NULL, routine_philo, &p[i]) != 0)
				return (exit_philo_routine(p, i));
	}
	else
	{
		while (++i < p->settings->num_of_philo)
			if (pthread_create(&p[i].thread, NULL,
					routine_three_philo, &p[i]) != 0)
				return (exit_philo_routine(p, i));
	}
	return (true);
}
