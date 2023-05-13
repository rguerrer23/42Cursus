/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:22:47 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/09 17:22:47 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_print_hex(va_list *ap)
{
	unsigned int	n;
	int				x;
	char			*ptr;
	size_t			i;

	n = va_arg(*ap, unsigned int);
	va_end(*ap);
	i = ft_counthex(n);
	x = i;
	if (n == 0)
	{
		ft_putchar(x + '0');
		return (1);
	}
	ptr = (char *)malloc(i + 1);
	ptr[i] = 0;
	while (n > 0)
	{
		ptr[i - 1] = "0123456789abcdef"[n % 16];
		n = n / 16;
		i--;
	}
	ft_putstr(ptr);
	return (free(ptr), x);
}
