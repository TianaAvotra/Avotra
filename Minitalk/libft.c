/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:43:39 by hrasolom          #+#    #+#             */
/*   Updated: 2024/07/15 11:25:34 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' || *nptr == '\f'
		|| *nptr == '\r' || *nptr == ' ')
		++nptr;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign *= -1;
	while ('0' <= *nptr && *nptr <= '9')
	{
		ret *= 10;
		ret += (*(nptr++) - '0');
	}
	return (ret * sign);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
