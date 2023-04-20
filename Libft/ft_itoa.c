/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:05:38 by rguerrer          #+#    #+#             */
/*   Updated: 2023/04/20 15:55:27 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
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
	int		j;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = malloc(sizeof(char) * (ft_lenint(n) + 1));
	if (!ptr)
		return (NULL);
	x = 0;
	j = 1;
	if (n < 0)
	{
		n *= -1;
		ptr[x] = '-';
		x++;
		j = 0;
	}
	while (n > 0)
	{
		ptr[ft_lenint(n) - j] = n % 10 + '0';
		n /= 10;
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}
