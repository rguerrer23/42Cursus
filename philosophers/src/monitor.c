/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:18:51 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/08 17:18:51 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_num_meals(t_philo *philo)
{
	int		i;
	int		Check;

	i = 0;
	Check = 0;
	while(i < philo->num_of_philos)
		if (philo[i].meals_eaten >= philo[i].num_times_to_eat)
			Check++;
	if (Check == philo->num_of_philos)
	{
		pthread_mutex_lock(philo->dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_lock(philo->write_lock);
		printf("All philos ate %d times\n", philo->num_times_to_eat);
		pthread_mutex_unlock(philo->write_lock);
		return (1);
	}
	return (0);
}

int	ft_check_died(t_philo *philo)
{
	int		i;

	i = 0;
	while(i < philo->num_of_philos)
	{
		if (philo[i].time_to_die < ft_get_time() - philo[i].last_meal)
		{
			pthread_mutex_lock(philo[i].dead_lock);
			*philo[i].dead = 1;
			pthread_mutex_unlock(philo[i].dead_lock);
			pthread_mutex_lock(philo[i].write_lock);
			printf("%zu %d died\n", ft_get_time() - philo[i].start_time, philo[i].id);
			pthread_mutex_unlock(philo[i].write_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (ft_check_died(philos) == 1 || ft_check_num_meals(philos) == 1)
			break ;
	}
	return (arg);
}