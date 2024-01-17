/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:38:13 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/17 18:57:42 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_game(t_game *game)
{
	game->mlx = mlx_init(game->map_height, game->map_width, "so_long", false);
	return (1);
}
