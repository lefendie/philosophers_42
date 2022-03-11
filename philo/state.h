/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:06:54 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/04 13:40:12 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

int	print_message(int state, t_data *data, t_philo *current_philo,
		pthread_mutex_t *mutex);
int	philo_die(t_data *data, t_philo *curr_philo,
		pthread_mutex_t *main_mutex);

#endif
