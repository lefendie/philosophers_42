/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:40:54 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/11 17:44:17 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*even_philo_living_his_best_life_definite(void *philo)
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_philo			*current_philo;
	t_data			*data;

	current_philo = init_routine(philo, &data, &fork_left, &fork_right);
	while (1)
	{
		if (!even_take_fork(current_philo, fork_left, fork_right, data))
			break ;
		if (!print_message(EAT, data, current_philo, data->main_mutex))
			break ;
		usleep(data->timetoeat);
		pthread_mutex_lock(current_philo->mutex);
		(*current_philo->eat_count)++;
		pthread_mutex_unlock(current_philo->mutex);
		even_leave_forks(current_philo, fork_left, fork_right);
		if (!print_message(SLEEP, data, current_philo, data->main_mutex))
			break ;
		usleep(data->timetosleep);
		if (!print_message(THINK, data, current_philo, data->main_mutex))
			break ;
		usleep(data->ttl_min);
	}
	return (NULL);
}

void	*uneven_philo_living_his_best_life_definite(void *philo)
{
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	t_philo			*current_philo;
	t_data			*data;

	current_philo = init_routine(philo, &data, &mutex_left, &mutex_right);
	while (1)
	{
		if (!uneven_take_fork(philo, mutex_left, mutex_right, data))
			break ;
		if (!print_message(EAT, data, current_philo, data->main_mutex))
			break ;
		usleep(data->timetoeat);
		pthread_mutex_lock(current_philo->mutex);
		(*current_philo->eat_count)++;
		pthread_mutex_unlock(current_philo->mutex);
		uneven_leave_forks(current_philo, mutex_left, mutex_right);
		if (!print_message(SLEEP, data, current_philo, data->main_mutex))
			break ;
		usleep(data->timetosleep);
		if (!print_message(THINK, data, current_philo, data->main_mutex))
			break ;
		usleep(data->ttl_min);
	}
	return (NULL);
}

void	*even_philo_living_his_best_life(void *philo)
{
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	t_philo			*current_philo;
	t_data			*data;

	current_philo = init_routine(philo, &data, &mutex_left, &mutex_right);
	while (1)
	{
		if (!even_take_fork(current_philo, mutex_left, mutex_right, data))
			break ;
		if (!print_message(EAT, data, current_philo, data->main_mutex))
			break ;
		usleep(data->timetoeat);
		even_leave_forks(current_philo, mutex_left, mutex_right);
		if (!print_message(SLEEP, data, current_philo, data->main_mutex))
			break ;
		usleep(data->timetosleep);
		if (!print_message(THINK, data, current_philo, data->main_mutex))
			break ;
		usleep(data->ttl_min);
	}
	return (NULL);
}

void	*uneven_philo_living_his_best_life(void *philo)
{
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	t_philo			*current_philo;
	t_data			*data;

	current_philo = init_routine(philo, &data, &mutex_left, &mutex_right);
	while (1)
	{
		if (!uneven_take_fork(philo, mutex_left, mutex_right, data))
			break ;
		if (!print_message(EAT, data, current_philo, data->main_mutex))
			break ;
		usleep(data->timetoeat);
		uneven_leave_forks(current_philo, mutex_left, mutex_right);
		if (!print_message(SLEEP, data, current_philo, data->main_mutex))
			break ;
		usleep(data->timetosleep);
		if (!print_message(THINK, data, current_philo, data->main_mutex))
			break ;
		usleep(data->ttl_min);
	}
	return (NULL);
}

void	*lone_philo_living_sad_life_alone(void *philo)
{
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	t_philo			*current_philo;
	t_data			*data;

	current_philo = init_routine(philo, &data, &mutex_left, &mutex_right);
	if (!print_message(FORK1, data, current_philo, data->main_mutex))
		return (NULL);
	while (1)
	{	
		pthread_mutex_lock(data->main_mutex);
		if (data->dead)
		{
			pthread_mutex_unlock(data->main_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(data->main_mutex);
		usleep(500);
	}	
	return (NULL);
}
