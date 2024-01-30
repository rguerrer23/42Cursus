/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:49:09 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/30 13:21:58 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *str, char *ext)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (ext[j] != '\0')
		j++;
	if (i < j)
		return (0);
	while (j >= 0)
	{
		if (str[i] != ext[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

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
				mlx_image_to_window(game->mlx->mlx, game->img->img_wall, x * 32,
					y * 32);
			else if (game->map[y][x] == 'P')
			{
				game->mlx->player_x = x;
				game->mlx->player_y = y;
				mlx_image_to_window(game->mlx->mlx, game->img->img_floor, x
					* 32, y * 32);
				mlx_image_to_window(game->mlx->mlx, game->img->img_player, x
					* 32, y * 32);
			}
			else if (game->map[y][x] == 'X')
			{
				mlx_image_to_window(game->mlx->mlx, game->img->img_exit, x * 32,
					y * 32);
				mlx_image_to_window(game->mlx->mlx, game->img->img_player, x
					* 32, y * 32);
			}
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx->mlx, game->img->img_exit, x * 32,
					y * 32);
			else if (game->map[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx->mlx, game->img->img_floor, x
					* 32, y * 32);
				mlx_image_to_window(game->mlx->mlx, game->img->img_collect, x
					* 32, y * 32);
			}
			else
				mlx_image_to_window(game->mlx->mlx, game->img->img_floor, x
					* 32, y * 32);
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

	tmp_map = ft_calloc(BUFF_SIZE, sizeof(char));
	if (!tmp_map)
		return (0);
	fd = open(script_map, O_RDONLY);
	if (fd < 0)
	{
		free(tmp_map);
		return (0);
	}
	x = read(fd, tmp_map, BUFF_SIZE);
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
