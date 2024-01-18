/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:38:13 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 13:45:54 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	if (!game->mlx)
		return (0);
	ft_load_pngs(game);
	ft_get_images(game);
	ft_draw_map(game);
	ft_key_hook(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_free_map(game->map);
	return (1);
}
