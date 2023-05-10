/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:56:20 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/09 19:51:50 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

int	ft_print_str(va_list *ap)
{
	int		x;
	char	*str;

	str = va_arg(*ap, char *);
	va_end(*ap);
	x = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[x] != '\0')
	{
		ft_putchar(str[x]);
		x++;
	}
	return (ft_strlen(str));
}
