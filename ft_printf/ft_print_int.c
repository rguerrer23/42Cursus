/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:33:48 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/06 19:33:48 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenint(long n)
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

char	*ft_strdup(const char *s1)
{
	char		*des;
	int			x;
	int			y;
	int			z;

	z = 0;
	x = 0;
	while (s1[z] != '\0')
	{
		x++;
		z++;
	}
	des = (char *)malloc((x) * sizeof(char) + 1);
	y = 0;
	if (des != NULL)
	{
		while (s1[y] != '\0')
		{
			des[y] = s1[y];
			y++;
		}
		des[y] = '\0';
		return (des);
	}
	return (NULL);
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

int	ft_print_int(va_list *ap)
{
	int		nb;
	int		cuent;
	char	*ptr;

	nb = va_arg(*ap, long);
	va_end(*ap);
	ptr = ft_itoa(nb);
	cuent = ft_lenint(nb);
	ft_putstr(ptr);
	return (free(ptr), cuent);
}
