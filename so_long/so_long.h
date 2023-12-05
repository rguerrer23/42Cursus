/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:10:32 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/02 11:10:32 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*floor;
	int		width;
	int		height;
}				t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}				t_game;

int		init_images(t_game *game);
void	run_game(t_game *game);
void	end_game(t_game *game);
int     main(int argc, char **argv);
int 	init_game(t_game *game, char *map_path);

#endif