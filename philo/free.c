/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:35:40 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 20:31:32 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_all(t_data *data, t_philo *philo_list)
{
	int	i;
	int	nb_philo;

	i = 0;
	nb_philo = data->nb_philo;
	while (i < nb_philo)
	{
		free(philo_list[i].thread);
		if (pthread_mutex_destroy(philo_list[i].mutex))
			return (-1);
		free(philo_list[i].mutex);
		free(philo_list[i].eat_time);
		free(philo_list[i].eat_count);
		free(philo_list[i].full);
		if (pthread_mutex_destroy(data->fork_list[i]->mutex))
			return (-1);
		free(data->fork_list[i]->mutex);
		free(data->fork_list[i]);
		i++;
	}
	free(philo_list);
	free(data->fork_list);
	return (0);
}
