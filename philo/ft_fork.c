/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:28:42 by hrasolom          #+#    #+#             */
/*   Updated: 2024/12/07 11:35:46 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork_philo_pair(t_philo *philo, long time)
{
	if (philo->fork_left)
	{
		pthread_mutex_lock(philo->fork_left);
		ft_print(philo, 4, time);
		usleep(1);
	}
	if (philo->fork_right)
	{
		pthread_mutex_lock(philo->fork_right);
		ft_print(philo, 4, time);
	}
}

void	take_fork(t_philo *philo, long time)
{
	int	dead_flag;

	pthread_mutex_lock(&philo->data->mutex_dead);
	dead_flag = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->mutex_dead);
	if (philo->index % 2 == 0)
	{
		take_fork_philo_pair(philo, time);
	}
	else
	{
		if (philo->fork_right)
		{
			pthread_mutex_lock(philo->fork_right);
			ft_print(philo, 4, time);
			usleep(1);
		}
		if (philo->fork_left)
		{
			pthread_mutex_lock(philo->fork_left);
			ft_print(philo, 4, time);
		}
	}
}

void	unlocked_fork(t_philo *philo)
{
	ft_usleep(philo->time_to_eat, philo);
	if (philo->index % 2 == 0)
	{
		if (philo->fork_right)
			pthread_mutex_unlock(philo->fork_right);
		if (philo->fork_left)
			pthread_mutex_unlock(philo->fork_left);
	}
	else
	{
		if (philo->fork_left)
			pthread_mutex_unlock(philo->fork_left);
		if (philo->fork_right)
			pthread_mutex_unlock(philo->fork_right);
	}
}

void	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while ((i) < data->philo->nbr_philo)
	{
		pthread_mutex_init(&data->philo->fork[i], NULL);
		if (data->philo->nbr_philo == 1)
		{
			data->philo[i].fork_right = NULL;
			data->philo[i].fork_left = &(data->philo->fork[(i + 1)
					% (data->philo->nbr_philo)]);
		}
		else
		{
			data->philo[i].fork_right = &(data->philo->fork[i]);
			data->philo[i].fork_left = &(data->philo->fork[(i + 1)
					% (data->philo->nbr_philo)]);
		}
		i++;
	}
}
