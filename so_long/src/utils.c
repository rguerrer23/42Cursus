/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:40:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/30 13:26:04 by rguerrer         ###   ########.fr       */
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
	int	y;

	y = 0;
	game->map_width = ft_strlen(map[0]) * 32;
	while (map[y] != NULL)
		y++;
	game->map_height = y * 32;
}

void	ft_print_moves(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_close_game(t_game *game)
{
	mlx_terminate(game->mlx->mlx);
	ft_free_map(game->map);
	exit(0);
}
