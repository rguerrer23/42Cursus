/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:13:22 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/02 11:13:22 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_map(t_game *game, char *map_path)
{
	int fd;
	char *line;
	int ret;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = 1;
	while (ret)
	{
		//ret = get_next_line(fd, &line);
		if (ret == -1)
			return (0);
		game->map.height++;
		if (game->map.width == 0)
			game->map.width = ft_strlen(line);
		free(line);
	}
	close(fd);
	game->map.grid = ft_calloc(game->map.height, sizeof(char *));
	if (!game->map.grid)
		return (0);
	return (1);
}

int init_player(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		game->map.grid[x] = ft_calloc(game->map.width, sizeof(char));
		if (!game->map.grid[x])
			return (0);
		while (y < game->map.width)
		{
			game->map.grid[x][y] = '0';
			y++;
		}
		x++;
	}
	return (1);
}

int init_collectibles(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.grid[x][y] == 'C')
				game->collectibles++;
			y++;
		}
		x++;
	}
	return (1);
}

int init_exits(t_game *game)
{
	int x;
	int y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (game->map.grid[x][y] == 'E')
				game->exits++;
			y++;
		}
		x++;
	}
	return (1);
}

int init_game(t_game *game, char *map_path)
{
	if (!init_map(game, map_path))
		return (0);
	if (!init_player(game))
		return (0);
	if (!init_collectibles(game))
		return (0);
	if (!init_exits(game))
		return (0);
	if (!init_images(game))
		return (0);
	return (1);
}