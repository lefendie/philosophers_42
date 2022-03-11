/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:26:32 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/04 14:29:38 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parameters_invalid(ac, av))
		return (0);
	else if (ac == 5)
	{
		if (infinite_loop(&data, av) == -1)
			return (-1);
	}
	else if (ac == 6)
	{
		if (definite_loop(&data, av) == -1)
			return (-1);
	}
	return (0);
}
