/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:20:08 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/04 11:20:08 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_images(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &game->img.width, &game->img.height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &game->img.width, &game->img.height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, "./img/collectible.xpm", &game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &game->img.width, &game->img.height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &game->img.width, &game->img.height);
	if (!game->img.player || !game->img.wall || !game->img.collectible || !game->img.exit || !game->img.floor)
		return (0);
	return (1);
}