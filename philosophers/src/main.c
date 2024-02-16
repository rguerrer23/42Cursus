/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:40:44 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/08 13:28:35 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_program	program;
	t_philo		philo;
	pthread_mutex_t	*forks;

	if (ac != 5 && ac != 6)
		ft_error("Wrong number of arguments\n");
	if (!ft_check_args(ac, av))
		ft_error("Invalid arguments\n");
	ft_init_program(&program, &philo);
	ft_init_forks(&forks, av[1]);
	ft_init_philos(&philo, av, &program, forks);
	ft_start_threads(&program, forks);
	return (0);
}