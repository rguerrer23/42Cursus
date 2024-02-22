/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:48:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/22 12:19:08 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_nums(char **av)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 2147483647)
		return (1);
	return (0);
}

int	ft_check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ft_check_nums(av) == 1)
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
