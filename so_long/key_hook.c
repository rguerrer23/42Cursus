/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:46:10 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 13:48:07 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_hook(t_game *game)
{
	mlx_key_hook(game->mlx->win, ft_key_press, game);
	mlx_hook(game->mlx->win, 33, 1L << 17, ft_close, game);
	mlx_loop(game->mlx);
}