/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_punt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:35:23 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/05 16:35:13 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

size_t	ft_counthex(unsigned long n)
{
	size_t	x;

	x = 0;
	while (n > 0)
	{
		n = n / 16;
		x++;
	}
	return (x);
}

int	ft_print_punt(va_list *ap)
{
	unsigned long	n;
	int				x;
	char			*ptr;
	char			*hex;
	size_t			i;

	n = va_arg(*ap, unsigned long);
	hex = "0123456789abcdef";
	i = ft_counthex(n);
	x = i;
	ptr = (char *)malloc(i + 1);
	ptr[i] = 0;
	while (n > 0)
	{
		ptr[i - 1] = hex[n % 16];
		n = n / 16;
		i--;
	}
	while (*ptr)
	{
		ft_putchar(*ptr);
		ptr++;
	}
	return (x);
}
