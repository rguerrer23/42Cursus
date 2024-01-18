/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:48:29 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 11:15:35 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("Invalid number of arguments\n");
	game.map = ft_read_map(av[1]);
	if (!game.map)
		return (1);
	if (!ft_check_map(game.map))
		return (ft_free_map(game.map), 1);
	ft_size_map(game.map, &game);
	if (!ft_init_game(&game))
		return (1);
	return (0);
}
