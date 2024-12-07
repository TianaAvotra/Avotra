/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:31:25 by hrasolom          #+#    #+#             */
/*   Updated: 2024/12/07 14:46:40 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_flag(t_philo *philo)
{
	int	dead_flag;

	dead_flag = 0;
	pthread_mutex_lock(&philo->data->mutex_dead);
	dead_flag = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->mutex_dead);
	return (dead_flag);
}

int	ft_check_death_util(t_philo *philo, long long *start)
{
	long long	time;

	(void)start;
	philo->time_to_check = ft_get_current();
	time = philo->time_to_check - philo->last_meal;
	if (time >= philo->time_to_dead)
	{
		pthread_mutex_unlock(&philo->data->meals_lock);
		pthread_mutex_lock(&philo->data->mutex_dead);
		philo->data->dead_flag = 1;
		pthread_mutex_unlock(&philo->data->mutex_dead);
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d died\n", get_time_start(*start), philo->index + 1);
		pthread_mutex_unlock(&philo->data->print);
		return (1);
	}
	return (0);
}

int	ft_check_death(t_philo *philo, int *i, long long *start)
{
	while (*i < philo->nbr_philo)
	{
		pthread_mutex_lock(&philo[*i].data->meals_lock);
		if (ft_check_death_util(&philo[*i], start) == 1)
		{
			return (1);
		}
		pthread_mutex_unlock(&philo[*i].data->meals_lock);
		(*i)++;
	}
	return (0);
}

int	ft_check_meal(t_philo *philo)
{
	int	a;

	a = philo->nbr_philo * philo->nbr_meals;
	pthread_mutex_lock(&philo->data->meals_lock);
	if (philo->nbr_meals > 0 && philo->meals_eating > philo->nbr_meals)
	{
		philo->flags++;
		pthread_mutex_unlock(&philo->data->meals_lock);
		if (philo->flags > a)
		{
			pthread_mutex_lock(&philo->data->mutex_dead);
			philo->data->dead_flag = 1;
			pthread_mutex_unlock(&philo->data->mutex_dead);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->meals_lock);
	return (0);
}

void	ft_check_meals_eating(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[i].nbr_philo)
	{
		if (philo[i].nbr_meals)
		{
			philo[i].meals_eating++;
		}
		i++;
	}
}
