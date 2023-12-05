/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:48:29 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/30 16:48:29 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        ft_putstr_fd("Error: wrong number of arguments\n", 2);
        return (1);
    }
    if (!init_game(&game, argv[1]))
    {
        ft_putstr_fd("Error: could not initialize game\n", 2);
        return (1);
    }
    run_game(&game);
    end_game(&game);
    return (0);	
}