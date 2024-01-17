/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/17 18:44:13 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_size_map(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->map_height = 0;
	game->map_width = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
			x++;
		if (x > game->map_width)
			game->map_width = x;
		y++;
	}
	game->map_height = y;
}
