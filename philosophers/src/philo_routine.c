/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:03:35 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/16 16:26:24 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead_loop(t_philo *ph)
{
	pthread_mutex_lock(ph->dead_lock);
	if (*ph->dead == 1)
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
	ft_print_status(ph, "has taken a fork\n", ph->id);
	if (ph->num_of_philos == 1)
	{
		ft_usleep(ph->time_to_die);
		pthread_mutex_unlock(ph->r_fork);
		return ;
	}
	pthread_mutex_lock(ph->l_fork);
	ft_print_status(ph, "has taken a fork\n", ph->id);
	ph->eating = 1;
	ft_print_status(ph, "is eating\n", ph->id);
	pthread_mutex_lock(ph->meal_lock);	
	ph->last_meal = ft_get_time();	
	ph->meals_eaten++;
	pthread_mutex_unlock(ph->meal_lock);
	ft_usleep(ph->time_to_eat);
	ph->eating = 0;
	pthread_mutex_unlock(ph->r_fork);
	pthread_mutex_unlock(ph->l_fork);
}

void	ft_sleep(t_philo *ph)
{
	ft_print_status(ph, "is sleeping\n", ph->id);
	ft_usleep(ph->time_to_sleep);
}

void	ft_think(t_philo *ph)
{
	ft_print_status(ph, "is thinking\n", ph->id);
}

void	*ft_philo_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->id % 2 == 0)
		ft_usleep(1);
	while (!ft_dead_loop(ph))
	{
		ft_eat(ph);
		ft_sleep(ph);
		ft_think(ph);
	}
	return (philo);
}