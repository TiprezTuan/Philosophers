/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:02:58 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/13 09:37:08 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "struct.h"
#include "philosophers.h"

static void	init_mutex(t_p_settings *p_settings)
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

void	*routine_philo(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&p->settings->philo_died_mutex);
		if (p->settings->philo_died)
		{
			pthread_mutex_unlock(&p->settings->philo_died_mutex);
			break ;
		}
		pthread_mutex_unlock(&p->settings->philo_died_mutex);
		pthread_mutex_lock(&p->settings->philo_eat_all_mutex);
		if (p->settings->philo_eat_all)
		{
			pthread_mutex_unlock(&p->settings->philo_eat_all_mutex);
			break ;
		}
		pthread_mutex_unlock(&p->settings->philo_eat_all_mutex);
		thinking(p);
		eating(p);
		sleeping(p);
	}
	return (arg);
}

bool	start_all_philo_routine(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->settings->num_of_philo)
	{
		if (pthread_create(&p[i].thread, NULL, routine_philo, &p[i]) != 0)
		{
			while (--i >= 0)
				pthread_join(p[i].thread, NULL);
			return (false);
		}
	}
	return (true);
}
