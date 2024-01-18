/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:49:09 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 11:10:46 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(char *script_map)
{
	int		fd;
	char	*tmp_map;
	char	**map;
	int		x;

	tmp_map = ft_calloc(432423, sizeof(char));
	if (!tmp_map)
		return (0);
	fd = open(script_map, O_RDONLY);
	if (fd < 0)
	{
		free(tmp_map);
		return (0);
	}
	x = read(fd, tmp_map, 432423);
	if (x < 0)
	{
		free(tmp_map);
		close(fd);
		return (0);
	}
	map = ft_split(tmp_map, '\n');
	free(tmp_map);
	close(fd);
	return (map);
}
