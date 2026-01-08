/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:37:20 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/08 18:18:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>

long	current_time_ms()
{
	struct timeval	current_tv;

	gettimeofday(&current_tv, NULL);
	return (current_tv.tv_sec * 1000 + current_tv.tv_usec / 1000);
}

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
