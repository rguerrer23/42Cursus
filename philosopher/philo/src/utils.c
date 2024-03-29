/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:42:09 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/20 11:54:18 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, char *str, int id)
{
	pthread_mutex_lock(philo->write_lock);
	if (!ft_dead_loop(philo))
	{
		ft_putnbr_fd(ft_get_time() - philo->start_time, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(id, 1);
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(str, 1);
	}
	pthread_mutex_unlock(philo->write_lock);
}

void	ft_destroy_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

size_t	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error getting time\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(500);
	return (0);
}
