/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:30:01 by hrasolom          #+#    #+#             */
/*   Updated: 2024/12/07 11:38:52 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	to_think(t_philo *philo, long long time)
{
	int	i;

	i = philo->time_to_eat - philo->time_to_sleep;
	ft_print(philo, 1, time);
	if (philo->nbr_philo % 2 != 0 && i >= 0)
	{
		ft_usleep(philo->time_to_eat, philo);
	}
}

void	to_sleep(t_philo *philo, long long time)
{
	ft_print(philo, 2, time);
	ft_usleep(philo->time_to_sleep, philo);
}

int	to_eat(t_philo *philo, long long time)
{
	long long	last_time;
	int			dead_flag;

	pthread_mutex_lock(&philo->data->mutex_dead);
	dead_flag = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->mutex_dead);
	if (dead_flag == 0)
	{
		take_fork(philo, time);
		if (philo->fork_right == NULL)
		{
			pthread_mutex_unlock(philo->fork_left);
			ft_usleep(philo->time_to_eat, philo);
			return (1);
		}
		pthread_mutex_lock(&philo->data->meals_lock);
		last_time = ft_get_current();
		philo->last_meal = last_time;
		ft_check_meals_eating(philo);
		pthread_mutex_unlock(&philo->data->meals_lock);
		ft_print(philo, 3, time);
		unlocked_fork(philo);
	}
	return (0);
}
