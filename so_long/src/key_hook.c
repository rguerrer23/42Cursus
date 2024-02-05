/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:46:10 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/01 12:42:24 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	int	new_y;
	int	new_x;
	int	exit;

	exit = 0;
	new_y = game->mlx->player_y - 1;
	new_x = game->mlx->player_x;
	if (game->map[new_y][new_x] != '1')
	{
		handle_collectible(game, new_y, new_x);
		exit = handle_exit(game, new_y, new_x);
		if (exit == 0)
			move_player(game, new_y, new_x);
	}
}

void	ft_move_down(t_game *game)
{
	int	new_y;
	int	new_x;
	int	exit;

	exit = 0;
	new_y = game->mlx->player_y + 1;
	new_x = game->mlx->player_x;
	if (game->map[new_y][new_x] != '1')
	{
		handle_collectible(game, new_y, new_x);
		exit = handle_exit(game, new_y, new_x);
		if (exit == 0)
			move_player(game, new_y, new_x);
	}
}

void	ft_move_left(t_game *game)
{
	int	new_y;
	int	new_x;
	int	exit;

	exit = 0;
	new_y = game->mlx->player_y;
	new_x = game->mlx->player_x - 1;
	if (game->map[new_y][new_x] != '1')
	{
		handle_collectible(game, new_y, new_x);
		exit = handle_exit(game, new_y, new_x);
		if (exit == 0)
			move_player(game, new_y, new_x);
	}
}

void	ft_move_right(t_game *game)
{
	int	new_y;
	int	new_x;
	int	exit;

	exit = 0;
	new_y = game->mlx->player_y;
	new_x = game->mlx->player_x + 1;
	if (game->map[new_y][new_x] != '1')
	{
		handle_collectible(game, new_y, new_x);
		exit = handle_exit(game, new_y, new_x);
		if (exit == 0)
			move_player(game, new_y, new_x);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *pa)
{
	t_game	*game;

	game = (t_game *)pa;
	ft_collects(game);
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_close_game(game);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_move_up(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_move_down(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_move_left(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_move_right(game);
}
