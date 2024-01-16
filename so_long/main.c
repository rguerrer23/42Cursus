/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:48:29 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/16 13:32:35 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "MLX42/include/MLX42/MLX42.h"

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
 
	mlx_ptr = mlx_init(256, 256, "42Balls", true);
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_image(mlx_ptr, 600, 400);
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
	return (EXIT_SUCCESS);
}
