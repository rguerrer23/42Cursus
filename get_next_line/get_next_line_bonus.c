/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:42:42 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/15 17:43:48 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfile(int fd, char *buffer)
{
	char	*temp;
	int		x;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	x = 1;
	while (!ft_strchr(buffer, '\n') && x > 0)
	{
		x = read(fd, temp, BUFFER_SIZE);
		if (x == -1)
		{
			free(buffer);
			return (NULL);
		}
		temp[x] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	return (free(temp), buffer);
}

char	*ft_line(char *buffer)
{
	int		x;
	char	*line;

	x = 0;
	if (!buffer[x])
		return (NULL);
	while (buffer[x] != '\n' && buffer[x])
		x++;
	line = ft_calloc(x + 2, sizeof(char));
	x = 0;
	while (buffer[x] != '\n' && buffer[x])
	{
		line[x] = buffer[x];
		x++;
	}
	if (buffer[x] == '\n' && buffer[x])
		line[x++] = '\n';
	return (line);
}

char	*ft_clear(char *buffer)
{
	int		x;
	int		y;
	char	*buffer_clear;

	x = 0;
	while (buffer[x] != '\n' && buffer[x])
		x++;
	if (!buffer[x])
		return (free(buffer), NULL);
	buffer_clear = ft_calloc((ft_strlen(buffer) - x + 1), sizeof(char));
	if (!buffer_clear)
		return (free(buffer), NULL);
	x++;
	y = 0;
	while (buffer[x])
	{
		buffer_clear[y] = buffer[x];
		x++;
		y++;
	}
	return (free(buffer), buffer_clear);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_readfile(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer = ft_clear(buffer[fd]);
	return (line);
}
