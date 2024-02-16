/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:59:12 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/08 13:09:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_threads(t_program *program, pthread_mutex_t *forks)
{
	int	i;
	pthread_t	observer;

	i = 0;
	if (pthread_create(&observer, NULL, ft_monitor, program->philos) != 0)
		ft_destroy_all("Error creating thread\n", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &ft_philo_routine, &program->philos[i]) != 0)
			ft_destroy_all("Error creating thread\n", program, forks);
		i++;
	}
	i = 0;
	if(pthread_join(observer, NULL) != 0)
		ft_destroy_all("Error joining thread\n", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			ft_destroy_all("Error joining thread\n", program, forks);
		i++;
	}
	return (0);
}