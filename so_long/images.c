/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:30:16 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 11:49:17 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	game->img->img_wall = mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm",
			32, 32);
	game->img->img_player = mlx_xpm_file_to_image(game->mlx, "./images/player.xpm",
			32, 32);
	
}