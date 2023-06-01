/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:15:25 by rguerrer          #+#    #+#             */
/*   Updated: 2023/06/01 18:29:20 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		*((unsigned char *)s + x) = '\0';
		x++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		x;
	int		y;

	x = 0;
	y = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!s1 || !s2 || !str)
		return (NULL);
	while (s1[x])
		str[y++] = s1[x++];
	x = 0;
	while (s2[x])
		str[y++] = s2[x++];
	str[y] = '\0';
	return (str);
}
