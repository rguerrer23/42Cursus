/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:30:16 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 13:28:11 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_pngs(t_game *game)
{
	game->png = ft_calloc(1, sizeof(t_img));
	game->png->img_wall = mlx_load_png("./img/wall.png");
	game->png->img_player = mlx_load_png("./img/player.png");
	game->png->img_exit = mlx_load_png("./img/exit.png");
	printf("img_exit: %p\n", game->png->img_exit);
	game->png->img_collect = mlx_load_png("./img/collect.png");
	game->png->img_floor = mlx_load_png("./img/floor.png");
	//quitar el if despues de verificar que todo funciona
	//if (!game->png->img_wall || !game->png->img_player || !game->png->img_exit
	//	|| !game->png->img_collect || !game->png->img_floor)
	//	ft_error("Error\nImage not found");
}

void	ft_get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	game->img->img_wall = mlx_texture_to_image(game->mlx, game->png->img_wall);
	game->img->img_player = mlx_texture_to_image(game->mlx,
			game->png->img_player);
	game->img->img_exit = mlx_texture_to_image(game->mlx, game->png->img_exit);
	game->img->img_collect = mlx_texture_to_image(game->mlx,
			game->png->img_collect);
	game->img->img_floor = mlx_texture_to_image(game->mlx,
			game->png->img_floor);
	mlx_delete_texture(game->png->img_wall);
	mlx_delete_texture(game->png->img_player);
	mlx_delete_texture(game->png->img_exit);
	mlx_delete_texture(game->png->img_collect);
	mlx_delete_texture(game->png->img_floor);
}
