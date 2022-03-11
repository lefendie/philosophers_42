/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:39:32 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 20:53:44 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_all_threads(t_data *data, t_philo *philo_list)
{
	int	j;
	int	nb_philo;

	nb_philo = data->nb_philo;
	j = 0;
	if (nb_philo == 1)
	{
		pthread_join(*(philo_list[0].thread), NULL);
		return (0);
	}
	while (j < nb_philo)
	{
		pthread_join(*(philo_list[j].thread), NULL);
		j++;
	}
	pthread_mutex_destroy(data->main_mutex);
	data->main_mutex = NULL;
	return (0);
}

int	create_philo_infinite(t_philo *current_philo, int i)
{
	if (i % 2 == 0)
	{
		if (pthread_create(current_philo->thread, NULL,
				even_philo_living_his_best_life, current_philo) != 0)
			return (-1);
	}
	else
	{
		if (pthread_create(current_philo->thread, NULL,
				uneven_philo_living_his_best_life, current_philo) != 0)
			return (-1);
	}
	return (0);
}

int	create_all_thread(t_data *data, t_philo *philo_list,
		pthread_mutex_t *main_mutex)
{
	int				i;

	i = -1;
	data->dead = 0;
	data->count_full_philo = 0;
	pthread_mutex_init(main_mutex, NULL);
	data->main_mutex = main_mutex;
	data->start_time = init_time_stamp();
	pthread_mutex_lock(main_mutex);
	if (data->nb_philo == 1)
	{
		if (pthread_create(philo_list[0].thread, NULL,
				lone_philo_living_sad_life_alone, &(philo_list[0])) != 0)
			return (-1);
		i++;
	}
	while (++i < data->nb_philo)
	{
		if (create_philo_infinite(&philo_list[i], i) != 0)
			return (-1);
	}
	pthread_mutex_unlock(main_mutex);
	return (0);
}

int	create_philo_definite(t_philo *current_philo, int i)
{
	if (i % 2 == 0)
	{
		if (pthread_create(current_philo->thread, NULL,
				even_philo_living_his_best_life_definite, current_philo) != 0)
			return (-1);
	}
	else
	{
		if (pthread_create(current_philo->thread, NULL,
				uneven_philo_living_his_best_life_definite, current_philo) != 0)
			return (-1);
	}
	return (0);
}

int	create_all_thread_definite(t_data *data, t_philo *philo_list,
		pthread_mutex_t *main_mutex)
{
	int				i;

	i = -1;
	data->dead = 0;
	data->count_full_philo = 0;
	pthread_mutex_init(main_mutex, NULL);
	data->main_mutex = main_mutex;
	data->start_time = init_time_stamp();
	pthread_mutex_lock(main_mutex);
	if (data->nb_philo == 1)
	{
		if (pthread_create(philo_list[0].thread, NULL,
				lone_philo_living_sad_life_alone, &(philo_list[0])) != 0)
			return (-1);
		i++;
	}
	while (++i < data->nb_philo)
	{
		if (create_philo_definite(&philo_list[i], i) != 0)
			return (-1);
	}
	pthread_mutex_unlock(main_mutex);
	return (0);
}
