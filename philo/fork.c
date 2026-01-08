/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:02:03 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/08 18:18:14 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>

#include "philosophers.h"
#include "struct.h"

void	take_fork(t_philo *p)
{
	pthread_mutex_lock(&p->right_fork->mutex);
	pthread_mutex_lock(&p->left_fork->mutex);

	p->last_meal = current_time_ms();
}

void	drop_fork(t_philo *p)
{
	pthread_mutex_unlock(&p->right_fork->mutex);
	pthread_mutex_unlock(&p->left_fork->mutex);
}