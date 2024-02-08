/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:03:35 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/08 13:04:24 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead_loop(t_philo *ph)
{
	pthread_mutex_lock(ph->dead_lock);
	if (*ph->dead)
	{
		pthread_mutex_unlock(ph->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(ph->dead_lock);
	return (0);
}

void	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->r_fork);
	printf("%zu %d has taken a fork\n", ft_get_time() - ph->start_time, ph->id);
	pthread_mutex_lock(ph->l_fork);
	printf("%zu %d has taken a fork\n", ft_get_time() - ph->start_time, ph->id);
	printf("%zu %d is eating\n", ft_get_time() - ph->start_time, ph->id);
	ph->last_meal = ft_get_time();
	ph->meals_eaten++;
	ft_usleep(ph->time_to_eat * 1000);
	pthread_mutex_unlock(ph->r_fork);
	pthread_mutex_unlock(ph->l_fork);
	pthread_mutex_lock(ph->meal_lock);
	pthread_mutex_unlock(ph->meal_lock);
}

void	ft_sleep(t_philo *ph)
{
	printf("%zu %d is sleeping\n", ft_get_time() - ph->start_time, ph->id);
	usleep(ph->time_to_sleep * 1000);
}

void	ft_think(t_philo *ph)
{
	printf("%zu %d is thinking\n", ft_get_time() - ph->start_time, ph->id);
	if (ph->num_times_to_eat != -1 && ph->meals_eaten == ph->num_times_to_eat)
	{
		pthread_mutex_lock(ph->dead_lock);
		*ph->dead = 1;
		pthread_mutex_unlock(ph->dead_lock);
	}
}

void	*ft_philo_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (!ft_dead_loop(ph))
	{
		ft_eat(ph);
		ft_sleep(ph);
		ft_think(ph);
	}
	return (philo);
}