/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:25:56 by hrasolom          #+#    #+#             */
/*   Updated: 2024/12/05 15:40:00 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	check_nbr_argc(int argc)
{
	if (!(argc >= 5 && argc <= 6))
	{
		ft_putendl_fd("Invalid argc", 2);
		return (1);
	}
	return (0);
}

long	ft_atol(char *str)
{
	long	result;
	long	sign;
	long	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_is_nbr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_argv_argc(char **argv, int argc)
{
	int	i;

	i = 1;
	if (!(argc >= 5 && argc <= 6))
	{
		ft_putendl_fd("Invalid argc", 2);
		return (1);
	}
	while (argv[i])
	{
		if (ft_is_nbr(argv[i]) == 0 || ft_atol(argv[i]) <= 0)
		{
			ft_putendl_fd("Invalid number", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
