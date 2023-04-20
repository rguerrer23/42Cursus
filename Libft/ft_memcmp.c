/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:36:22 by rguerrer          #+#    #+#             */
/*   Updated: 2023/04/19 15:38:03 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*c;
	unsigned char	*y;

	x = 0;
	c = (unsigned char *)s1;
	y = (unsigned char *)s2;
	while (x < n)
	{
		if (((unsigned char)c[x]) != (unsigned char)y[x])
			return (((unsigned char)c[x]) - ((unsigned char)y[x]));
		x++;
	}
	return (0);
}
