/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:18:51 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/16 15:59:10 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_num_meals(t_philo *philo)
{
	int		i;
	int		Check;

	i = 0;
	Check = 0;
	if (philo[0].num_times_to_eat == -1)
		return (0);
	while(i < philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].num_times_to_eat)
			Check++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (Check == philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo->dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	return (0);
}

int	ft_check_died(t_philo *philo)
{
	int		i;

	i = 0;
	while(i < philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].time_to_die <= ft_get_time() - philo[i].last_meal && philo[i].eating == 0)
		{
			ft_print_status(philo, "died\n", philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		pthread_mutex_unlock(philo[i].meal_lock);
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