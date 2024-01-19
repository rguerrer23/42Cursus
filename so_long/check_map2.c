/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:25:31 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/19 18:38:01 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(char **map)
{
	char	**tmpmap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	tmpmap = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		tmpmap[i] = ft_calloc(j + 1, sizeof(char));
		j = 0;
		while (map[i][j])
		{
			tmpmap[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (tmpmap);
}

void	ft_start_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	dfs(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	else
		map[y][x] = 'V';
	dfs(map, x + 1, y);
	dfs(map, x - 1, y);
	dfs(map, x, y + 1);
	dfs(map, x, y - 1);
}

int	ft_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'V')
				return (1);
			j++;
		}
		i++;
	}
	ft_free_map(map);
	return (0);
}

int	ft_way(char **map)
{
	char **tmpmap;
	int	x;
	int	y;

	y = 0;
	x = 0;
	tmpmap = ft_copy_map(map);
	ft_start_pos(tmpmap, &x, &y);
	dfs(tmpmap, x, y);
	return (ft_check(tmpmap));
}