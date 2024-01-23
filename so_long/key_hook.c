/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:46:10 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/23 13:29:30 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_game(t_game *game)
{
	mlx_terminate(game->mlx->mlx);
	ft_free_map(game->map);
	exit(0);
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->mlx->player_y - 1][game->mlx->player_x] != '1')
	{
		if (game->map[game->mlx->player_y - 1][game->mlx->player_x] == 'C')
			game->mlx->collects--;
		if (game->map[game->mlx->player_y - 1][game->mlx->player_x] == 'E' && game->mlx->collects == 0)
			ft_close_game(game);
		game->map[game->mlx->player_y][game->mlx->player_x] = '0';
		game->mlx->player_y--;
		game->map[game->mlx->player_y][game->mlx->player_x] = 'P';
		game->moves++;
		ft_draw_map(game);
		printf("Moves: %d\n", game->moves);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->mlx->player_y + 1][game->mlx->player_x] != '1')
	{
		if (game->map[game->mlx->player_y + 1][game->mlx->player_x] == 'C')
			game->mlx->collects--;
		if (game->map[game->mlx->player_y + 1][game->mlx->player_x] == 'E' && game->mlx->collects == 0)
			ft_close_game(game);
		game->map[game->mlx->player_y][game->mlx->player_x] = '0';
		game->mlx->player_y++;
		game->map[game->mlx->player_y][game->mlx->player_x] = 'P';
		game->moves++;
		ft_draw_map(game);
		printf("Moves: %d\n", game->moves);
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->mlx->player_y][game->mlx->player_x - 1] != '1')
	{
		if (game->map[game->mlx->player_y][game->mlx->player_x - 1] == 'C')
			game->mlx->collects--;
		if (game->map[game->mlx->player_y][game->mlx->player_x - 1] == 'E' && game->mlx->collects == 0)
			ft_close_game(game);
		game->map[game->mlx->player_y][game->mlx->player_x] = '0';
		game->mlx->player_x--;
		game->map[game->mlx->player_y][game->mlx->player_x] = 'P';
		game->moves++;
		ft_draw_map(game);
		printf("Moves: %d\n", game->moves);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->mlx->player_y][game->mlx->player_x + 1] != '1')
	{
		if (game->map[game->mlx->player_y][game->mlx->player_x + 1] == 'C')
			game->mlx->collects--;
		if (game->map[game->mlx->player_y][game->mlx->player_x + 1] == 'E' && game->mlx->collects == 0)
			ft_close_game(game);
		game->map[game->mlx->player_y][game->mlx->player_x] = '0';
		game->mlx->player_x++;
		game->map[game->mlx->player_y][game->mlx->player_x] = 'P';
		game->moves++;
		ft_draw_map(game);
		printf("Moves: %d\n", game->moves);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *pa)
{
	t_game	*game;

	game = (t_game *)pa;
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
	if(game->mlx->collects == 0 && game->map[game->mlx->player_y][game->mlx->player_x] == 'E')
		ft_close_game(game);
	//ft_collects(game);
}
