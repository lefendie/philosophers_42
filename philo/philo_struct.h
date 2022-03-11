/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:24:28 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/11 18:43:43 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <pthread.h>

typedef struct s_fork
{
	pthread_mutex_t	*mutex;
	int							*taken;
	int							*next_philo;
}								t_fork;

typedef struct s_philo	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*main_mutex;
	t_philo			*philo_list;
	t_fork			**fork_list;
	long			start_time;
	int				nb_philo;
	int				timetoeat;
	int				timetosleep;
	int				timetolive;
	int				eat_count;
	int				count_full_philo;
	int				dead;
	int				ttl_min;
}							t_data;

typedef struct s_philo
{
	pthread_mutex_t	*mutex;
	pthread_t		*thread;
	t_data			*data;
	int				*eat_time;
	int				id;
	int				*eat_count;
	int				*full;
	int				*eating;
}								t_philo;

#endif
