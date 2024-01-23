/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:21:40 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/23 11:24:30 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**handle_single_quote(char const **s, char **ptr, int *x)
{
	ptr[*x] = substrig(++(*s), 39);
	*s = ft_strchr(*s, 39);
	if (!ptr[*x] || !*s)
		return (limpiar(ptr));
	(*x)++;
	(*s)++;
	return (ptr);
}

char	**handle_double_quote(char const **s, char **ptr, int *x)
{
	ptr[*x] = substrig(++(*s), 34);
	*s = ft_strchr(*s, 34);
	if (!ptr[*x] || !*s)
		return (limpiar(ptr));
	(*x)++;
	(*s)++;
	return (ptr);
}

char	**handle_other_char(char const **s, char c, char **ptr, int *x)
{
	ptr[*x] = substrig(*s, c);
	if (!ptr[*x])
		return (limpiar(ptr));
	while (**s && **s != c)
		(*s)++;
	(*x)++;
	return (ptr);
}
