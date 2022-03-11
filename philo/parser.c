/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:07:21 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/11 18:43:56 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parameters_invalid(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_str_numeric(av[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	alloc_fork_list(t_fork *current_fork)
{
	current_fork = malloc(sizeof(t_fork));
	if (!current_fork)
		return (-1);
	current_fork->mutex = malloc(sizeof(pthread_mutex_t));
	if (!current_fork->mutex)
		return (-1);
	if (pthread_mutex_init(current_fork->mutex, NULL) != 0)
		return (-1);
	current_fork->taken = malloc(sizeof(int));
	if (!current_fork->taken)
		return (-1);
	current_fork->next_philo = malloc(sizeof(int));
	if (!current_fork->next_philo)
		return (-1);
	return (0);	
}

int	fill_fork_list(t_data *data)
{
	t_fork	**fork_list;
	int		j;

	fork_list = malloc(sizeof(t_fork) * (data->nb_philo + 2));
	if (!fork_list)
		return (-1);
	j = -1;
	while (++j <= data->nb_philo)
	{
		if (j == data->nb_philo)
			fork_list[j] = fork_list[0];
		else
			alloc_fork_list(fork_list[j]);
	}
	data->fork_list = fork_list;
	return (0);
}

int	alloc_philo_list(t_philo *current_philo)
{
	current_philo->thread = malloc(sizeof(pthread_t));
	if (!current_philo->thread)
		return (-1);
	current_philo->eat_time = malloc(sizeof(int));
	if (!current_philo->eat_time)
		return (-1);
	current_philo->mutex = malloc(sizeof(pthread_mutex_t));
	if (!current_philo->mutex)
		return (-1);
	current_philo->eat_count = malloc(sizeof(int));
	if (!current_philo->eat_count)
		return (-1);
	current_philo->eating = malloc(sizeof(int));
	if (!current_philo->eating)
		return (-1);
	current_philo->full = malloc(sizeof(int));
	if (!current_philo->full)
		return (-1);
	return (0);
}

int	fill_philo_list(t_philo **philo_list, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		if (alloc_philo_list(&((*philo_list)[i])) == -1)
			return (-1);
		if (pthread_mutex_init(((*philo_list)[i]).mutex, NULL) != 0)
			return (-1);
		*((*philo_list)[i]).eat_time = 0;
		((*philo_list)[i]).id = i + 1;
		*((*philo_list)[i]).eating = 0;
		((*philo_list)[i]).data = data;
		*((*philo_list)[i]).eat_count = 0;
	}
	return (0);
}

int	get_philosophers(t_data *data, char **av, t_philo **philo_list)
{
	data->nb_philo = ft_atoi(av[1]);
	data->timetoeat = ft_atoi(av[3]) * 1000;
	data->timetosleep = ft_atoi(av[4]) * 1000;
	data->timetolive = ft_atoi(av[2]);
	data->ttl_min = ((data->timetolive * 1000)
			- data->timetoeat - data->timetosleep) - 500;
	if (av[5])
		data->eat_count = ft_atoi(av[5]);
	*philo_list = malloc(sizeof(t_philo) * (data->nb_philo + 1));
	if (!*philo_list)
		return (-1);
	if (fill_philo_list(philo_list, data) == -1)
		return (-1);
	if (fill_fork_list(data) == -1)
		return (-1);
	data->philo_list = *philo_list;
	return (0);
}
