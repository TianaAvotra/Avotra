/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:41:57 by hrasolom          #+#    #+#             */
/*   Updated: 2024/11/30 15:52:44 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *data, int *i)
{
	data->philo[*i].last_meal = ft_get_current();
	data->philo[*i].index = *i;
	data->dead_flag = 0;
	data->philo[*i].time_to_check = 0;
	data->philo[*i].data = data;
	data->philo[*i].meals_eating = 0;
	data->philo[*i].flags = 0;
}

void	init_mutex(t_data *data)
{
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->mutex_dead), NULL);
	pthread_mutex_init(&(data->meals_lock), NULL);
}

void	init_time_to_eat_sleep(t_data data, int *i, int a, int b)
{
	data.philo[*i].time_to_eat = a;
	data.philo[*i].time_to_sleep = b;
}
