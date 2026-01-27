/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:18:55 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/27 13:49:10 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include "struct.h"

/*				utils.c					*/
int				ft_atoi(const char *src);
long			current_time_ms(void);
void			print_status(t_philo *p, long timestamp, const char *status);
bool			is_simulation_over(t_p_settings *p_settings);

/*			error_management.c			*/
void			destroy_i_mutex(t_philo **p, int i_p, t_fork **f, int i_f);
void			free_all(t_philo *p, t_fork *f, t_p_settings *p_settings);
void			destroy_and_exit(int exit_code, int nb_mutex, ...);

/*				  fork.c				*/
bool			init_forks(t_fork **f, t_p_settings *p_settings);
void			take_fork(t_philo *p);
void			drop_fork(t_philo *p);

/*				  philo.c				*/
t_p_settings	init_p_settings(int ac, char const **av);
bool			init_philo(t_philo **p, t_fork *f, t_p_settings *p_settings);
bool			start_all_philo_routine(t_philo *p);

/*				hypervisor.c			*/
void			hypervisor(t_philo *p, t_p_settings *p_settings);
void			join_all(t_philo *p, t_p_settings *p_settings);
void			smart_sleep(long sleep_time, t_p_settings *p_settings);

/*				philo_action.c			*/
void			thinking(t_philo *p);
void			eating(t_philo *p);
void			sleeping(t_philo *p);

#endif
