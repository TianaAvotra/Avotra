/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:48:58 by hrasolom          #+#    #+#             */
/*   Updated: 2024/12/07 14:40:11 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->index + 1) % 2 == 0)
		usleep(100);
	while (check_dead_flag(philo) != 1)
	{
		if (to_eat(philo, philo->data->start) == 1)
			break ;
		to_sleep(philo, philo->data->start);
		to_think(philo, philo->data->start);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		if (check_dead_flag(philo) == 1)
			break ;
		if (ft_check_death(philo, &i, &(philo->data->start)) == 1)
			break ;
		if (ft_check_meal(philo) == 1)
			break ;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (check_argv_argc(argv, argc) == 1)
		return (1);
	data.philo = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	data.philo->fork = malloc(sizeof(pthread_mutex_t) * (ft_atol(argv[1])));
	if (error_allocation(data) == 1)
		return (1);
	init_mutex(&data);
	while (i < ft_atol(argv[1]))
	{
		data.philo[i].nbr_philo = ft_atol(argv[1]);
		data.philo[i].time_to_dead = ft_atol(argv[2]);
		init_time_to_eat_sleep(data, &i, ft_atol(argv[3]), ft_atol(argv[4]));
		if (argc == 6)
			data.philo[i].nbr_meals = ft_atol(argv[5]);
		else
			data.philo[i].nbr_meals = 0;
		init_struct(&data, &i);
		i++;
	}
	main_util(&data);
	return (0);
}
