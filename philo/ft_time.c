/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:24:26 by hrasolom          #+#    #+#             */
/*   Updated: 2024/12/07 14:46:28 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_current(long long *start)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putendl_fd("Error", 2);
	*start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

long long	get_time_start(long long start)
{
	struct timeval	curent;
	long long		current;

	current = 0;
	gettimeofday(&curent, NULL);
	current = (curent.tv_sec * 1000) + (curent.tv_usec / 1000);
	return (current - start);
}

long long	ft_get_current(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putendl_fd("Error", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(long long time, t_philo *philo)
{
	long long	start;

	start = ft_get_current();
	while (ft_get_current() - start < time && (check_dead_flag(philo) != 1))
	{
		usleep(500);
	}
	return (0);
}
