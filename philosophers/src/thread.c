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

void	ft_start_threads(t_program *program)
{
	int	i;
	pthread_t	observer;

	i = 0;
	if (pthread_create(&observer, NULL, ft_monitor, program->philos) != 0)
		ft_error("Error creating thread\n");
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &ft_philo_routine, &program->philos[i]) != 0)
			ft_error("Error creating thread\n");
		i++;
	}
	i = 0;
	if(pthread_join(observer, NULL) != 0)
		ft_error("Error joining thread\n");
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			ft_error("Error joining thread\n");
		i++;
	}
}