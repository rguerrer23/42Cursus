/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:48:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/22 11:57:58 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_nums(int ac, char **av)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 200)
		return (1);
	else if (ft_atoi(av[2]) > 2147483647)
		return (1);
	else if (ft_atoi(av[3]) > 2147483647)
		return (1);
	else if (ft_atoi(av[4]) > 2147483647)
		return (1);
	else if (ac == 6 && ft_atoi(av[5]) > 2147483647)
		return (1);
	return (0);
}

int	ft_check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ft_check_nums(ac, av) == 1)
		return (0);
	while (i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (0);
		i++;
	}
	return (1);
}
