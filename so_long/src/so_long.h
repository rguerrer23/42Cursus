/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:10:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/30 13:26:10 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 5000

typedef struct s_mlx
{
	void			*mlx;
	int				player_x;
	int				player_y;
	int				collects;
}					t_mlx;

typedef struct s_img
{
	mlx_image_t		*img_wall;
	mlx_image_t		*img_player;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_floor;
}					t_img;

typedef struct s_png
{
	void			*img_wall;
	void			*img_player;
	void			*img_exit;
	void			*img_collect;
	void			*img_floor;
}					t_png;

typedef struct s_game
{
	struct s_img	*img;
	struct s_png	*png;
	struct s_mlx	*mlx;
	char			**map;
	int				map_height;
	int				map_width;
	int				moves;
}					t_game;

int					main(int argc, char **argv);
int					ft_check_map(char **map);
char				**ft_read_map(char *script_map);
void				ft_error(char *str);
void				ft_free_map(char **map);
void				ft_size_map(char **map, t_game *game);
int					ft_init_game(t_game *game);
void				ft_get_images(t_game *game);
void				ft_draw_map(t_game *game);
void				ft_load_pngs(t_game *game);
void				ft_key_hook(mlx_key_data_t keydata, void *pa);
int					ft_check_extension(char *str, char *ext);
int					ft_way(char **map);
void				ft_collects(t_game *game);
void				ft_print_moves(t_game *game);
int					ft_objects(char **map);
void				ft_close_game(t_game *game);

#endif