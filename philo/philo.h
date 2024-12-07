/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolom <hrasolom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:18:51 by hrasolom          #+#    #+#             */
/*   Updated: 2024/12/07 14:05:44 by hrasolom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct					s_philo
{
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	int					meals_eating;
	long long			last_meal;
	long long			time_to_check;
	pthread_mutex_t		*fork;
	pthread_t			thread;
	pthread_t			monitor_thread;
	int					flags;
	int					index;
	long				nbr_philo;
	long				time_to_eat;
	long				time_to_dead;
	long				time_to_sleep;
	long				nbr_meals;
	t_data				*data;
};

struct					s_data
{
	long long			start;
	int					dead_flag;
	long long			time;
	pthread_mutex_t		print;
	pthread_mutex_t		mutex_dead;
	pthread_mutex_t		meals_lock;
	t_philo				*philo;
};

void					init_time_to_eat_sleep(t_data data, int *i, int a,
							int b);
void					take_fork_philo_pair(t_philo *philo, long time);
void					ft_print(t_philo *philo, int n, long start);
void					ft_print_dead(t_philo *philo, long start);
void					ft_check_meals_eating(t_philo *philo);
void					take_fork(t_philo *philo, long time);
void					to_sleep(t_philo *philo, long long time);
void					to_think(t_philo *philo, long long time);
void					init_struct(t_data *data, int *i);
void					ft_putendl_fd(char *s, int fd);
void					unlocked_fork(t_philo *philo);
void					get_current(long long *start);
void					init_mutex(t_data *data);
void					init_fork(t_data *data);
void					main_util(t_data *data);
void					ft_pthread(t_data *data);
void					*monitor(void *arg);
void					*routine(void *arg);

int						ft_check_death(t_philo *philo, int *i,
							long long *start);
int						ft_usleep(long long time, t_philo *philo);
int						check_argv_argc(char **argv, int argc);
int						to_eat(t_philo *philo, long long time);
int						check_dead_flag(t_philo *philo);
int						ft_check_meal(t_philo *philo);
int						error_allocation(t_data data);
int						check_nbr_argc(int argc);
int						ft_is_nbr(char *s);

long					ft_atol(char *str);

long long				get_time_start(long long start);
long long				ft_get_current(void);

#endif