/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:37:20 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/13 09:36:20 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdarg.h>

#include "struct.h"

static char	*ft_skip_whitespace(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] == ' ' || (src[i] >= 9 && src[i] <= 13))
		i++;
	return ((char *)&src[i]);
}

void	destroy_and_exit(int exit_code, int nb_mutex, ...)
{
	pthread_mutex_t	current_mutex;
	va_list			all_mutex;
	int				i;

	va_start(all_mutex, nb_mutex);
	i = -1;
	while (++i < nb_mutex)
	{
		current_mutex = va_arg(all_mutex, pthread_mutex_t);
		pthread_mutex_destroy(&current_mutex);
	}
	va_end(all_mutex);
	exit(exit_code);
}

void	print_status(t_philo *p, long current_timestamp, const char *status)
{
	pthread_mutex_lock(&p->settings->print_mutex);
	pthread_mutex_lock(&p->settings->philo_died_mutex);
	pthread_mutex_lock(&p->settings->philo_eat_all_mutex);
	if (!p->settings->philo_died && !p->settings->philo_eat_all)
		printf(
			"%ld %d %s\n",
			current_timestamp - p->settings->start_timestamp,
			p->num_philo, status);
	pthread_mutex_unlock(&p->settings->philo_eat_all_mutex);
	pthread_mutex_unlock(&p->settings->philo_died_mutex);
	pthread_mutex_unlock(&p->settings->print_mutex);
}

long	current_time_ms(void)
{
	struct timeval	current_tv;

	gettimeofday(&current_tv, NULL);
	return (current_tv.tv_sec * 1000 + current_tv.tv_usec / 1000);
}

int	ft_atoi(const char *src)
{
	int		res;
	int		i;
	int		signe;
	char	*str;

	str = ft_skip_whitespace(src);
	res = 0;
	signe = 1;
	i = 0;
	if (str[0] == '-')
	{
		signe = -1;
		i = 1;
	}
	else if (str[0] == '+')
		i = 1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * signe);
}
