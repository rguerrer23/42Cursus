/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:13:49 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/31 19:06:52 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(int fd, char *buffer)
{
	char	*temp;
	int		x;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	x = 1;
	while (!ft_strchr(buffer, '\n') && x > 0)
	{
		x = read(fd, temp, BUFFER_SIZE);
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
	while (buffer[x] != '\n' && buffer[x] != '\0')
		x++;
	line = ft_calloc(x + 2, sizeof(char));
	if (!line)
		return (NULL);
	x = 0;
	while (buffer[x] != '\n' && buffer[x] != '\0')
	{
		line[x] = buffer[x];
		x++;
	}
	if (buffer[x] == '\n')
		line[x] = buffer[x];
	line[x++] = '\0';
	return (line);
}

char	*ft_clear(char *buffer)
{
	int		x;
	int		y;
	char	*buffer_clear;

	x = 0;
	while (buffer[x] != '\n')
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
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_readfile(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_clear(buffer);
	return (line);
}
