/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:14:58 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/08 17:14:58 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned int nb)
{
	int				larg;
	unsigned int	cp;

	larg = 1;
	cp = nb;
	while (cp >= 10)
	{
		cp /= 10;
		larg++;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
	return (larg);
}

int	ft_print_uint(va_list *ap)
{
	int	nb;

	nb = ft_putnbr(va_arg(*ap, unsigned int));
	va_end(*ap);
	return (nb);
}
