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
	return (0);
}