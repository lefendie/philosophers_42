/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:42:38 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 20:52:31 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

int	stop_all_threads(t_data *data, t_philo *philo_list);
int	create_philo_infinite(t_philo *current_philo, int i);
int	create_all_thread(t_data *data, t_philo *philo_list,
		pthread_mutex_t *main_mutex);
int	create_philo_definite(t_philo *current_philo, int i);
int	create_all_thread_definite(t_data *data, t_philo *philo_list,
		pthread_mutex_t *main_mutex);

#endif
