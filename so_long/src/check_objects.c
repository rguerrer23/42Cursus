/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:10:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/30 14:11:37 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_objects(char map_char, int *collectibles, int *exits, int *player)
{
	if (map_char == 'C')
		(*collectibles)++;
	else if (map_char == 'E')
		(*exits)++;
	else if (map_char == 'P')
		(*player)++;
}

void	process_map_line(char *map_line, int *collectibles, int *exits,
		int *player)
{
	int	x;

	x = 0;
	while (map_line[x] != '\0')
	{
		count_objects(map_line[x], collectibles, exits, player);
		x++;
	}
}

int	ft_objects(char **map)
{
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
		process_map_line(map[y], &collectibles, &exits, &player);
		y++;
	}
	if (collectibles <= 0 || exits != 1 || player != 1)
		return (0);
	return (1);
}
