/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:32:33 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/17 18:53:34 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rectangule(char **map)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = ft_strlen(map[0]);
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
			x++;
		if (x != len)
			return (0);
		y++;
	}
	return (1);
}

int	ft_walls(char **map)
{
	unsigned long	x;
	unsigned long	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (y == 0 || y == ft_strlen(map[0]) - 1)
			{
				if (map[y][x] != '1')
					return (0);
			}
			if (x == 0 || x == ft_strlen(map[y]) - 1)
			{
				if (map[y][x] != '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_objects(char **map)
{
	int	x;
	int	y;
	int	collectibles;
	int	exits;
	int	player;

	y = 0;
	collectibles = 0;
	exits = 0;
	player = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				collectibles++;
			if (map[y][x] == 'E')
				exits++;
			if (map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	if (collectibles <= 0 || exits != 1 || player != 1)
		return (0);
	return (1);
}

int	ft_chars(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_map(char **map)
{
	if (!ft_rectangule(map))
		return (ft_error("Map is not a rectangule\n"), 0);
	if (!ft_walls(map))
		return (ft_error("Map has no walls\n"), 0);
	if (!ft_objects(map))
		return (ft_error("Map has no objects\n"), 0);
	if (!ft_chars(map))
		return (ft_error("Map has invalid characters\n"), 0);
	//if (!ft_way(map))
		return (ft_error("Map has no way\n"), 0);
	return(1);
}
