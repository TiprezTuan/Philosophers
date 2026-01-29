/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:37:20 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/29 14:10:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>

#include "struct.h"
#include "philosophers.h"

static char	*ft_skip_whitespace(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] == ' ' || (src[i] >= 9 && src[i] <= 13))
		i++;
	return ((char *)&src[i]);
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

long	current_time_ms(void)
{
	struct timeval	current_tv;

	gettimeofday(&current_tv, NULL);
	return (current_tv.tv_sec * 1000 + current_tv.tv_usec / 1000);
}

void	print_status(t_philo *p, const char *status)
{
	pthread_mutex_lock(&p->settings->print_mutex);
	if (!is_simulation_over(p->settings))
		printf(
			"%ld %d %s\n",
			current_time_ms() - p->settings->start_timestamp,
			p->num_philo, status);
	pthread_mutex_unlock(&p->settings->print_mutex);
}

bool	is_simulation_over(t_p_settings *p_settings)
{
	bool	over;

	pthread_mutex_lock(&p_settings->philo_died_mutex);
	pthread_mutex_lock(&p_settings->philo_eat_all_mutex);
	over = (p_settings->philo_died || p_settings->philo_eat_all);
	pthread_mutex_unlock(&p_settings->philo_died_mutex);
	pthread_mutex_unlock(&p_settings->philo_eat_all_mutex);
	return (over);
}
