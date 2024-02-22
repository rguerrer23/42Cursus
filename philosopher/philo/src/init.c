/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:44:46 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/20 12:03:45 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo_values(t_philo *philo, char **av, int i)
{
	philo[i].id = i + 1;
	philo[i].eating = 0;
	philo[i].meals_eaten = 0;
	philo[i].last_meal = ft_get_time();
	philo[i].time_to_die = ft_atoi(av[2]);
	philo[i].time_to_eat = ft_atoi(av[3]);
	philo[i].time_to_sleep = ft_atoi(av[4]);
	philo[i].start_time = ft_get_time();
	philo[i].num_of_philos = ft_atoi(av[1]);
	if (av[5])
		philo[i].num_times_to_eat = ft_atoi(av[5]);
	else
		philo[i].num_times_to_eat = -1;
}

void	ft_init_philo_locks(t_philo *philo, t_program *program,
		pthread_mutex_t *forks, int i)
{
	philo[i].dead = &program->dead_flag;
	philo[i].write_lock = &program->write_lock;
	philo[i].dead_lock = &program->dead_lock;
	philo[i].meal_lock = &program->meal_lock;
	philo[i].l_fork = &forks[i];
	if (i == philo->num_of_philos - 1)
		philo[i].r_fork = &forks[0];
	else
		philo[i].r_fork = &forks[i + 1];
}

void	ft_init_philos(t_philo *philo, char **av, t_program *program,
		pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		ft_init_philo_values(philo, av, i);
		ft_init_philo_locks(philo, program, forks, i);
		i++;
	}
}

void	ft_init_forks(pthread_mutex_t *forks, char *num)
{
	int	i;

	i = 0;
	while (i < ft_atoi(num))
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	ft_init_program(t_program *program, t_philo *philo)
{
	program->dead_flag = 0;
	program->philos = philo;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}
