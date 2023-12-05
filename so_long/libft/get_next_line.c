/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:13:49 by rguerrer          #+#    #+#             */
/*   Updated: 2023/06/01 18:35:11 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line(char *buffer)
{
	int		x;
	char	*line;

	x = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[x] != '\n' && buffer[x])
		x++;
	if (buffer[x] == '\n')
		x++;
	line = ft_calloc(x + 1, sizeof(char));
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

char	*ft_liber(char *buffer, char *buftemp)
{
	char	*temp2;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp2 = ft_strjoin(buffer, buftemp);
	free (buffer);
	return (temp2);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer = NULL;
	char		*line;
	ssize_t		x;
	char		temp[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	x = 1;
	while (x > 0)
	{
		x = read(fd, temp, BUFFER_SIZE);
		if (x < 0)
			return (free(buffer), buffer = NULL, NULL);
		temp[x] = '\0';
		buffer = ft_liber(buffer, temp);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	*line = ft_line(buffer);
	buffer = ft_clear(buffer);
	if(!line)
		return(-1);
	if(x == 0)
		return(0);
	return(1);
}
