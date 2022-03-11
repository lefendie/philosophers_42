/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:36:31 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 20:16:23 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_ded(t_data *data, t_philo *current_philo, t_philo *philo_list)
{
	if (get_time_stamp(*current_philo->eat_time) > data->timetolive)
	{
		pthread_mutex_unlock(current_philo->mutex);
		philo_die(data, current_philo, data->main_mutex);
		stop_all_threads(data, philo_list);
		return (1);
	}
	return (0);
}

int	check_philo_full(t_data *data, t_philo *current_philo,
		t_philo *philo_list)
{
	int	eat_count;

	pthread_mutex_lock(data->main_mutex);
	eat_count = data->eat_count;
	pthread_mutex_unlock(data->main_mutex);
	if (*current_philo->eat_count == eat_count && !(*current_philo->full))
	{
		*current_philo->full = 1;
		pthread_mutex_unlock(current_philo->mutex);
		pthread_mutex_lock(data->main_mutex);
		data->count_full_philo++;
		pthread_mutex_unlock(data->main_mutex);
		return (0);
	}
	else if (data->count_full_philo == data->nb_philo)
	{
		pthread_mutex_unlock(current_philo->mutex);
		pthread_mutex_lock(data->main_mutex);
		data->dead = 1;
		pthread_mutex_unlock(data->main_mutex);
		stop_all_threads(data, philo_list);
		return (1);
	}
	pthread_mutex_unlock(current_philo->mutex);
	return (0);
}
