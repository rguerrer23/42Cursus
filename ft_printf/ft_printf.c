/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:23:12 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/05 16:41:01 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_choose(char elec, va_list *args)
{
	int	x;

	x = 0;
	if (elec == 'c')
		x += ft_print_char(args);
	else if (elec == 's')
		x += ft_print_str(args);
	else if (elec == 'p')
	{
		write (1, "0x", 2);
		x += ft_print_punt(args);
	}
	else if (elec == 'd' || elec == 'i')
		x += ft_print_int(args);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		cuent;
	int		z;

	cuent = 0;
	z = 0;
	va_start(args, str);
	if (str[0] == '\0')
		return (0);
	while (str[z])
	{
		if (str[z] == '%')
		{
			z++;
			cuent += ft_choose(str[z], &args);
		}
		else
		{
			ft_putchar(str[z]);
			cuent++;
		}
		z++;
	}
	return (cuent);
}
