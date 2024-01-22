/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:41:20 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/18 14:07:01 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**create_and_fill_array(char const *s, char c, char **ptr, int x)
{
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == 39)
		{
			if (!(ptr[x] = substrig(++s, 39)) || !(s = ft_strchr(s, 39)))
				return (limpiar(ptr));
			x++, s++;
		}
		else if (*s == 34)
		{
			if (!(ptr[x] = substrig(++s, 34)) || !(s = ft_strchr(s, 34)))
				return (limpiar(ptr));
			x++, s++;
		}
		else if (*s && *s != c)
		{
			if (!(ptr[x] = substrig(s, c)))
				return (limpiar(ptr));
			while (*s && *s != c)
                s++;
            x++;
        }
    }
    ptr[x] = NULL;
    return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (lenp(s, c) + 1));
	if (!ptr)
		return (NULL);
	return (create_and_fill_array(s, c, ptr, x));
}
