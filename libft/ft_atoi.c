/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:10:17 by hrasolom          #+#    #+#             */
/*   Updated: 2024/02/28 14:34:00 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*nptr == '\t'
		|| *nptr == '\n'
		|| *nptr == '\v'
		|| *nptr == '\f'
		|| *nptr == '\r'
		|| *nptr == ' ')
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
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%d",atoi("-545a"));
	printf("%d",ft_atoi("-545a"));
}*/
