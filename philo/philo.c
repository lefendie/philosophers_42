/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:27:34 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 17:53:47 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	uneven_take_fork(t_philo *current_philo, pthread_mutex_t *mutex_left,
		pthread_mutex_t *mutex_right, t_data *data)
{
	pthread_mutex_lock(mutex_right);
	if (!print_message(FORK1, data, current_philo, data->main_mutex))
		return (0);
	pthread_mutex_lock(mutex_left);
	if (!print_message(FORK2, data, current_philo, data->main_mutex))
		return (0);
	return (1);
}

int	even_take_fork(t_philo *current_philo, pthread_mutex_t *mutex_left,
		pthread_mutex_t *mutex_right, t_data *data)
{
	pthread_mutex_lock(mutex_left);
	if (!print_message(FORK1, data, current_philo, data->main_mutex))
		return (0);
	pthread_mutex_lock(mutex_right);
	if (!print_message(FORK2, data, current_philo, data->main_mutex))
		return (0);
	return (1);
}

void	even_leave_forks(t_philo *current_philo, pthread_mutex_t *mutex_left,
		pthread_mutex_t *mutex_right)
{
	pthread_mutex_unlock(mutex_right);
	pthread_mutex_unlock(mutex_left);
	update_last_meal(current_philo);
}

void	uneven_leave_forks(t_philo *current_philo, pthread_mutex_t *mutex_left,
		pthread_mutex_t *mutex_right)
{
	pthread_mutex_unlock(mutex_left);
	pthread_mutex_unlock(mutex_right);
	update_last_meal(current_philo);
}

t_philo	*init_routine(void *philo, t_data **data,
		pthread_mutex_t **mutex_left, pthread_mutex_t **mutex_right)
{
	t_philo	*current_philo;

	current_philo = (t_philo *)philo;
	*data = current_philo->data;
	*mutex_left = (*data)->fork_list[current_philo->id - 1]->mutex;
	*mutex_right = (*data)->fork_list[current_philo->id]->mutex;
	pthread_mutex_lock(current_philo->mutex);
	*(current_philo->eat_time) = init_time_stamp();
	pthread_mutex_unlock(current_philo->mutex);
	if (current_philo->id % 2 == 0)
		usleep(500);
	return (current_philo);
}
