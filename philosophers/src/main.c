/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:40:44 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/20 12:19:40 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (ac != 5 && ac != 6)
		ft_error("Wrong number of arguments\n");
	if (!ft_check_args(ac, av))
		ft_error("Invalid arguments\n");
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if (!philo || !forks)
		ft_error("Error allocating memory\n");
	ft_init_program(&program, philo);
	ft_init_forks(forks, av[1]);
	ft_init_philos(philo, av, &program, forks);
	ft_start_threads(&program, forks);
	ft_destroy_all(NULL, &program, forks);
	free(philo);
	free(forks);
	return (0);
}
