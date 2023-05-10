/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:23:12 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/10 20:36:33 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_choose(char elec, va_list *args)
{
	int	x;

	x = 0;
	if (elec == 'c')
		x += ft_print_char(args);
	else if (elec == 's')
		x += ft_print_str(args);
	else if (elec == 'p')
		x += ft_print_punt(args);
	else if (elec == 'd' || elec == 'i')
		x += ft_print_int(args);
	else if (elec == 'u')
		x += ft_print_uint(args);
	else if (elec == 'x')
		x += ft_print_hex(args);
	else if (elec == 'X')
		x += ft_print_hexcap(args);
	return (x);
}

void	ft_print_per(int *cuent)
{
	ft_putchar('%');
	*cuent = *cuent + 1;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		cuent;
	int		z;

	cuent = 0;
	z = 0;
	va_start(args, str);
	while (str[z])
	{
		if (str[z] != '%')
		{
			ft_putchar(str[z]);
			cuent++;
		}
		else
		{
			z++;
			if (str[z] == '%')
				ft_print_per(&cuent);
			else
				cuent += ft_choose(str[z], &args);
		}
		z++;
	}
	return (cuent);
}
