/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:05:38 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/02 18:06:41 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

int	ft_lenint(int n)
{
	int	x;

	x = 1;
	if (n < 0)
	{
		n *= -1;
		x++;
	}
	while (n >= 10)
	{
		n /= 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		x;
	int		nb;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = malloc(sizeof(char) * (ft_lenint(nb) + 1));
	if (!ptr)
		return (NULL);
	x = ft_lenint(nb);
	ptr[x--] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		ptr[0] = '-';
	}
	while (nb > 0)
	{
		ptr[x--] = nb % 10 + '0';
		nb /= 10;
	}
	return (ptr);
}
