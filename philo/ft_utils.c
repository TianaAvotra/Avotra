/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:34:49 by hrasolom          #+#    #+#             */
/*   Updated: 2024/12/07 14:44:41 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, int n, long start)
{
	pthread_mutex_lock(&philo->data->mutex_dead);
	if (philo->data->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex_dead);
		return ;
	}
	pthread_mutex_unlock(&philo->data->mutex_dead);
	pthread_mutex_lock(&philo->data->print);
	if (n == 1)
		printf("%lld %d is thinking\n", get_time_start(start), philo->index
			+ 1);
	else if (n == 2)
		printf("%lld %d is sleeping\n", get_time_start(start), philo->index
			+ 1);
	else if (n == 3)
		printf("%lld %d is eating\n", get_time_start(start), philo->index + 1);
	else if (n == 4)
		printf("%lld %d has taken a fork\n", get_time_start(start), philo->index
			+ 1);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_print_dead(t_philo *philo, long start)
{
	long long	time;

	time = 0;
	pthread_mutex_lock(&philo->data->mutex_dead);
	time = get_time_start(start);
	if (philo->data->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex_dead);
		return ;
	}
	pthread_mutex_unlock(&philo->data->mutex_dead);
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d died\n", time, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_pthread(t_data *data)
{
	int	i;

	i = 0;
	data->start = ft_get_current();
	while (i < data->philo->nbr_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		i++;
	}
	pthread_create(&data->philo->monitor_thread, NULL, monitor, data->philo);
	i = 0;
	while (i < data->philo->nbr_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_join(data->philo->monitor_thread, NULL);
	i = 0;
	while (i < data->philo->nbr_philo)
	{
		pthread_mutex_destroy(&data->philo->fork[i]);
		i++;
	}
}

void	main_util(t_data *data)
{
	init_fork(data);
	ft_pthread(data);
	pthread_mutex_destroy(&data->meals_lock);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->mutex_dead);
	free(data->philo->fork);
	free(data->philo);
}

int	error_allocation(t_data data)
{
	if (!data.philo || !data.philo->fork)
	{
		ft_putendl_fd("Memory allocation failed", 2);
		return (1);
	}
	return (0);
}
