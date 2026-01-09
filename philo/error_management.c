/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:04:08 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/09 12:35:35 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>

#include "struct.h"

void	destroy_i_mutex(t_philo **p, int i_p, t_fork **f, int i_f)
{
	if (*p)
	{
		while (--i_p >= 0)
			pthread_mutex_destroy(&(*p)[i_p].meal_mutex);
		free(*p);
	}
	if (*f)
	{
		while (--i_f >= 0)
			pthread_mutex_destroy(&(*f)[i_f].mutex);
		free(*f);
	}
}

void	free_all(t_philo *p, t_fork *f, int nb_philo)
{
	int	i;

	if (f)
	{
		i = -1;
		while (++i < nb_philo)
			pthread_mutex_destroy(&f[i].mutex);
		free(f);
	}
	if (p)
	{
		i = -1;
		while (++i < nb_philo)
			pthread_mutex_destroy(&p[i].meal_mutex);
		free(p);
	}
}