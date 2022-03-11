/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:31:46 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 19:54:43 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int	parameters_invalid(int ac, char **av);
int	ft_atoi(char *str);
int	infinite_loop(t_data *data, char **av);
int	get_philosophers(t_data *data, char **av, t_philo **philo_list);
int	ft_strlcpy(char *dst, const char *src, unsigned int size);
int	is_str_numeric(char *str);

#endif
