/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:54:19 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/11 21:11:11 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	handle_fork(t_philo *current_philo, t_fork **fork_list)
{
	int philo_id;

	philo_id = current_philo->id;
	if (current_philo->eating == 0)	
	{
		if (*fork_list[philo_id]->next_philo == philo_id && *fork_list[philo_id - 1]->next_philo == philo_id)
		{
			if (*fork_list[philo_id]->taken == 0 && *fork_list[philo_id - 1]->taken == 0)
			{
				*fork_list[philo_id]->taken = philo_id;
				*fork_list[philo_id - 1]->taken = philo_id;
				*current_philo->eating = 1;
				if (philo_id % 2 == 0)
				{
					*fork_list[philo_id]->taken = philo_id - 1;
					*fork_list[philo_id - 1]->taken = philo_id - 1;
				}
				else
				{
					*fork_list[philo_id]->taken = philo_id + 1;
					*fork_list[philo_id - 1]->taken = philo_id + 1;
				}
			}
		}
	}
}

int	infinite_loop(t_data *data, char **av)
{
	pthread_mutex_t	main_mutex;
	t_philo			*philo_list;
	int				i;

	if (get_philosophers(data, av, &philo_list) == -1)
		return (-1);
	if (create_all_thread(data, philo_list, &main_mutex))
		return (-1);
	i = -1;
	while (1)
	{
		if (++i > data->nb_philo - 1)
			i = 0;
		handle_fork(philo_list[i], data->fork_list);
		pthread_mutex_lock(philo_list[i].mutex);
		if (*(philo_list[i]).eat_time)
		{
			if (check_philo_ded(data, &philo_list[i], philo_list) == 1)
				break ;
		}
		pthread_mutex_unlock(philo_list[i].mutex);
		usleep(500);
	}
	free_all(data, philo_list);
	return (0);
}

int	definite_loop(t_data *data, char **av)
{
	pthread_mutex_t	main_mutex;
	t_philo			*philo_list;
	int				i;

	if (get_philosophers(data, av, &philo_list) == -1)
		return (-1);
	if (create_all_thread_definite(data, philo_list, &main_mutex))
		return (-1);
	i = -1;
	while (1)
	{
		if (++i > data->nb_philo - 1)
			i = 0;
		pthread_mutex_lock(philo_list[i].mutex);
		if (check_philo_full(data, &philo_list[i], philo_list) == 1)
			break ;
		pthread_mutex_lock(philo_list[i].mutex);
		if (*(philo_list[i]).eat_time
			&& check_philo_ded(data, &philo_list[i], philo_list) == 1)
			break ;
		pthread_mutex_unlock(philo_list[i].mutex);
		usleep(500);
	}
	free_all(data, philo_list);
	return (0);
}
