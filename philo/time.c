/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:29:48 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/02 23:49:58 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_stamp(int start)
{	
	struct timeval	actual_time;

	gettimeofday(&actual_time, NULL);
	return (((actual_time.tv_usec / 1000 + actual_time.tv_sec * 1000) - start));
}

int	init_time_stamp(void)
{	
	struct timeval	actual_time;

	gettimeofday(&actual_time, NULL);
	return (actual_time.tv_usec / 1000 + actual_time.tv_sec * 1000);
}
