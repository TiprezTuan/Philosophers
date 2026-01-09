/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:18:55 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/09 15:51:40 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "struct.h"

/*				utils.c					*/
long			current_time_ms();
int				ft_atoi(const char *src);

/*			error_management.c			*/
void			destroy_i_mutex(t_philo **p, int i_p, t_fork **f, int i_f);
void			free_all(t_philo *p, t_fork *f, int nb_philo);

/*				  fork.c				*/
bool			init_forks(t_fork **f, t_p_settings *p_settings);
void			take_fork(t_philo *p);
void			drop_fork(t_philo *p);

/*				  philo.c				*/
t_p_settings	init_p_settings(int ac, char const **av);
bool			init_philo(t_philo **p, t_fork *f, t_p_settings *p_settings);
bool			start_all_philo_routine(t_philo *p);

/*				hypervisor.c			*/
void			join_all(t_philo *p, t_p_settings *p_settings);
void			hypervisor(t_philo *p, t_p_settings *p_settings);

/*				philo_action.c			*/
void			thinking(t_philo *p);
void			eating(t_philo *p);
void			sleeping(t_philo *p);

#endif
