/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:19:37 by lefendie          #+#    #+#             */
/*   Updated: 2022/03/05 19:54:07 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	string_to_int;
	int	sign;

	sign = 1;
	string_to_int = 0;
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		string_to_int = string_to_int * 10 + (*str - 48);
		str++;
	}
	return (string_to_int * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

int	get_nb_size(int nb)
{
	int	size;

	size = 1;
	while (nb / 10 >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

int	put_int_in_message(char message[BUFFER], int nb)
{
	int	nb_size;
	int	i;

	nb_size = get_nb_size(nb);
	i = nb_size;
	while (i > -1)
	{
		message[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	nb_size += 1;
	message[nb_size] = ' ';
	return (nb_size);
}
