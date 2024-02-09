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

void	*ft_monitor(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philos[0].num_of_philos)
		{
			pthread_mutex_lock(philos[i].meal_lock);
			if (philos[i].num_times_to_eat != -1 && philos[i].meals_eaten == philos[i].num_times_to_eat)
			{
				pthread_mutex_lock(philos[i].dead_lock);
				*philos[i].dead = 1;
				pthread_mutex_unlock(philos[i].dead_lock);
			}
			pthread_mutex_unlock(philos[i].meal_lock);
			i++;
		}
	}
	return (arg);
}