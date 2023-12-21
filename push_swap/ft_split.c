/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:41:20 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/21 12:40:22 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenp(char const *s, char c)
{
	int	x;
	int	n;

	x = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[x] && s[x] == c)
		x++;
	while (s[x])
	{
		if (s[x + 1] == c || s[x + 1] == '\0')
		{
			n++;
			while (s[x + 1] != '\0' && s[x + 1] == c)
				x++;
		}
		x++;
	}
	return (n);
}

char	*substrig(char const *s, char c)
{
	char	*str;
	int		x;

	x = 0;
	while (s[x] && s[x] != c)
		x++;
	str = malloc(sizeof(char) * (x + 1));
	if (!str)
		return (NULL);
	x = 0;
	while (s[x] && s[x] != c)
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	**limpiar(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		x;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (lenp(s, c) + 1));
	if (!ptr)
		return (NULL);
	x = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			ptr[x] = substrig(s, c);
			if (!ptr[x++])
				return (limpiar(ptr));
			while (*s && *s != c)
				s++;
		}
	}
	ptr[x] = NULL;
	return (ptr);
}

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
