/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:35:23 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/04 15:49:07 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIFE_H
# define PHILO_LIFE_H

t_philo	*init_routine(void *philo, t_data **data,
			pthread_mutex_t **mutex_left, pthread_mutex_t **mutex_right);
int		take_right_fork(t_philo *current_philo, pthread_mutex_t *fork_mutex,
			t_data *data);
int		uneven_take_fork(t_philo *current_philo, pthread_mutex_t *left_mutex,
			pthread_mutex_t *right_fork, t_data *data);
void	uneven_leave_forks(t_philo *current_philo, pthread_mutex_t *mutex_left,
			pthread_mutex_t *mutex_right);
int		even_take_fork(t_philo *current_philo, pthread_mutex_t *left_fork,
			pthread_mutex_t *right_fork, t_data *data);
void	even_leave_forks(t_philo *current_philo, pthread_mutex_t *mutex_left,
			pthread_mutex_t *mutex_right);

#endif
