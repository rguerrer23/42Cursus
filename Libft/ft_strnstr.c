/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:12:20 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/02 18:12:17 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[x] != '\0' && x < len)
	{
		y = 0;
		while ((str[x + y] == to_find[y])
			&& (str[x + y] != '\0') && (x + y < len))
		{
			if (to_find[y + 1] == '\0')
				return ((char *)&str[x]);
			y++;
		}
		x++;
	}
	return (0);
}
