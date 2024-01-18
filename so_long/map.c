/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:49:09 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 13:40:43 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img->img_wall, x * 32, y * 32);
			else if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img->img_player, x * 32, y * 32);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img->img_exit, x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img->img_collect, x * 32, y * 32);
			else
				mlx_image_to_window(game->mlx, game->img->img_floor, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

char	**ft_read_map(char *script_map)
{
	int		fd;
	char	*tmp_map;
	char	**map;
	int		x;

	tmp_map = ft_calloc(432424, sizeof(char));
	if (!tmp_map)
		return (0);
	fd = open(script_map, O_RDONLY);
	if (fd < 0)
	{
		free(tmp_map);
		return (0);
	}
	x = read(fd, tmp_map, 432423);
	if (x < 0)
	{
		free(tmp_map);
		close(fd);
		return (0);
	}
	map = ft_split(tmp_map, '\n');
	free(tmp_map);
	close(fd);
	return (map);
}
