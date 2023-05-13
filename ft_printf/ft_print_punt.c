/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_punt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:35:23 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/13 12:07:19 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		write(1, &s[x], 1);
		x++;
	}
}

int	ft_print_punt(va_list *ap)
{
	unsigned long	n;
	int				x;
	char			*ptr;
	size_t			i;

	n = va_arg(*ap, unsigned long);
	va_end(*ap);
	i = ft_counthex(n);
	x = i;
	write (1, "0x", 2);
	if (n == 0)
	{
		ft_putchar('0');
		return (3);
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
	return (free(ptr), x + 2);
}
