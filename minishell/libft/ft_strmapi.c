/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:55:47 by rguerrer          #+#    #+#             */
/*   Updated: 2023/04/27 18:55:47 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		x;
	char	*prt;

	if (!s || !f)
		return (NULL);
	prt = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!prt)
		return (NULL);
	x = 0;
	while (s[x])
	{
		prt[x] = f(x, s[x]);
		x++;
	}
	prt[x] = '\0';
	return (prt);
}
