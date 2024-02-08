/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:40:44 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/01 18:40:44 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		return (ft_error("Wrong number of arguments\n"));
	if (!ft_check_args(ac, av))
		return (ft_error("Invalid arguments\n"));
	philo = ft_init_philo(ac, av);
	if (!philo)
		return (ft_error("Error initializing philosophers\n"));
	if (!ft_init_mutexes(philo))
		return (ft_error("Error initializing mutexes\n"));
	if (!ft_init_threads(philo))
		return (ft_error("Error initializing threads\n"));
	ft_destroy_mutexes(philo);
	ft_destroy_philo(philo);
	return (0);
}