/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:08:19 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/11 18:28:36 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <time.h>
# include <sys/time.h>

# define EAT 1
# define SLEEP 2
# define FORK1 3
# define FORK2 4
# define DIE 5
# define THINK 6
# define BUFFER 64
# define WANT_FORK 0
# define IS_EATING 1

# include "philo_struct.h"
# include "parser.h"
# include "state.h"
# include "time.h"
# include "philo_life.h"
# include "routine.h"
# include "thread.h"
# include "loop.h"
# include "tools.h"

#endif
