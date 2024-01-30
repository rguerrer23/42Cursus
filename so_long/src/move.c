/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:46:23 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/30 14:04:00 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_collectible(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
		game->mlx->collects--;
}

int	handle_exit(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E')
	{
		if (game->mlx->collects == 0)
		{
			ft_putstr_fd("You win!\n", 1);
			ft_close_game(game);
			return (0);
		}
		else
		{
			ft_putstr_fd("You need to collect all the coins!\n", 1);
			game->map[game->mlx->player_y][game->mlx->player_x] = '0';
			game->mlx->player_y = y;
			game->mlx->player_x = x;
			game->map[game->mlx->player_y][game->mlx->player_x] = 'X';
			game->moves++;
			ft_draw_map(game);
			game->map[game->mlx->player_y][game->mlx->player_x] = 'E';
			ft_print_moves(game);
			return (1);
		}
	}
	return (0);
}

void	move_player(t_game *game, int y, int x)
{
	if (game->map[game->mlx->player_y][game->mlx->player_x] != 'E')
		game->map[game->mlx->player_y][game->mlx->player_x] = '0';
	game->mlx->player_y = y;
	game->mlx->player_x = x;
	game->map[game->mlx->player_y][game->mlx->player_x] = 'P';
	game->moves++;
	ft_draw_map(game);
	ft_print_moves(game);
}
