/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:08:56 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/09 18:21:02 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
int		ft_print_char(va_list *ap);
void	ft_putchar(char c);
int		ft_print_str(va_list *ap);
int		ft_print_punt(va_list *ap);
int		ft_print_int(va_list *ap);
int		ft_print_uint(va_list *ap);
size_t	ft_counthex(unsigned long n);
int		ft_print_hex(va_list *ap);
int		ft_print_hexcap(va_list *ap);
void	ft_putstr(char *s);

#endif