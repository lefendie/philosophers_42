/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:09:08 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 20:43:44 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

void	update_last_meal(t_philo *current_philo);
int		get_time_stamp(int start);
int		test_alive(t_data *data);
int		init_time_stamp(void);
int		definite_loop(t_data *data, char **av);
int		check_philo_ded(t_data *data, t_philo *current_philo,
			t_philo *philo_list);
int		check_philo_full(t_data *data, t_philo *current_philo,
			t_philo *philo_list);

#endif
