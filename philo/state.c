/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:04:03 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 18:09:44 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_message(char *message, int start_time, int id, int state)
{
	int	i;

	memset(message, 0, BUFFER);
	i = put_int_in_message(message, get_time_stamp(start_time)) + 1;
	i += put_int_in_message((message + i), id) + 1;
	if (state == EAT)
		i += ft_strlcpy(message + i, "is eating\n", 11);
	else if (state == SLEEP)
		i += ft_strlcpy(message + i, "is sleeping\n", 13);
	else if (state == THINK)
		i += ft_strlcpy(message + i, "is thinking\n", 13);
	else if (state == DIE)
		i += ft_strlcpy(message + i, "died\n", 9);
	else if (state == FORK1 || state == FORK2)
		i += ft_strlcpy(message + i, "has taken a fork\n", 18);
	return (i);
}

void	unlock_fork_mutexes(int state, pthread_mutex_t *mutex_left,
		pthread_mutex_t *mutex_right, int even)
{
	if (state == FORK1 && !even)
		pthread_mutex_unlock(mutex_right);
	else if (state == FORK1 && even)
		pthread_mutex_unlock(mutex_left);
	else if ((state == FORK2 || state == EAT) && !even)
	{
		pthread_mutex_unlock(mutex_left);
		pthread_mutex_unlock(mutex_right);
	}	
	else if ((state == FORK2 || state == EAT) && even)
	{
		pthread_mutex_unlock(mutex_right);
		pthread_mutex_unlock(mutex_left);
	}
}

int	print_message(int state, t_data *data, t_philo *current_philo,
		pthread_mutex_t *mutex)
{
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	char			message[64];
	int				size;
	int				even;

	size = get_message(message, data->start_time, current_philo->id, state);
	pthread_mutex_lock(mutex);
	if (data->dead)
	{
		even = current_philo->id % 2;
		pthread_mutex_unlock(mutex);
		mutex_right = data->fork_list[current_philo->id]->mutex;
		mutex_left = data->fork_list[current_philo->id - 1]->mutex;
		unlock_fork_mutexes(state, mutex_left, mutex_right, even);
		return (0);
	}
	pthread_mutex_unlock(mutex);
	pthread_mutex_lock(mutex);
	write(1, message, size);
	pthread_mutex_unlock(mutex);
	return (1);
}

int	philo_die(t_data *data, t_philo *curr_philo, pthread_mutex_t *main_mutex)
{
	char	message[BUFFER];
	int		size;

	size = get_message(message, data->start_time, curr_philo->id, DIE);
	pthread_mutex_lock(main_mutex);
	write(1, message, size);
	data->dead = 1;
	pthread_mutex_unlock(main_mutex);
	return (0);
}

void	update_last_meal(t_philo *current_philo)
{
	pthread_mutex_lock(current_philo->mutex);
	*(current_philo->eat_time) = init_time_stamp();
	pthread_mutex_unlock(current_philo->mutex);
}
