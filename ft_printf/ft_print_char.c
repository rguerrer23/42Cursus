/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:54:16 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/05 13:59:00 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_char(va_list *ap)
{
	ft_putchar(va_arg(*ap, int));
	va_end(*ap);
	return (1);
}
