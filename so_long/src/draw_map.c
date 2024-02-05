/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:49:16 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/05 16:00:19 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx->mlx, game->img->img_wall, x * 32, y * 32);
}

void	draw_player(t_game *game, int x, int y)
{
	game->mlx->player_x = x;
	game->mlx->player_y = y;
	mlx_image_to_window(game->mlx->mlx, game->img->img_floor, x * 32, y * 32);
	mlx_image_to_window(game->mlx->mlx, game->img->img_player, x * 32, y * 32);
}

void	draw_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx->mlx, game->img->img_exit, x * 32, y * 32);
	else
	{
		mlx_image_to_window(game->mlx->mlx, game->img->img_exit, x * 32, y * 32);
		mlx_image_to_window(game->mlx->mlx, game->img->img_player, x * 32, y * 32);
	}
}

void	draw_collect(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx->mlx, game->img->img_floor, x * 32, y * 32);
	mlx_image_to_window(game->mlx->mlx, game->img->img_collect, x * 32, y * 32);
}

void	draw_floor(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx->mlx, game->img->img_floor, x * 32, y * 32);
}
