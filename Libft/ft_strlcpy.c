/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:49:12 by rguerrer          #+#    #+#             */
/*   Updated: 2023/04/19 15:40:26 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;

	x = ft_strlen(src);
	y = 0;
	if (dstsize != 0)
	{
		while (src[y] != '\0' && y < dstsize -1)
		{
			dst[y] = src[y];
			y++;
		}
		dst[y] = '\0';
	}
	return (x);
}
