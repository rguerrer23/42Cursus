/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collects.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:59:01 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/30 13:13:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collects(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->mlx->collects = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->mlx->collects++;
			x++;
		}
		y++;
	}
}
