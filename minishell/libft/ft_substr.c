/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:08:16 by rguerrer          #+#    #+#             */
/*   Updated: 2023/04/20 12:18:48 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dst;
	unsigned int		i;
	unsigned int		leng;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		leng = ft_strlen(s) - start;
	else
		leng = len;
	dst = malloc(sizeof(char) * (leng + 1));
	if (!s || !(dst))
		return (NULL);
	i = 0;
	while (start < ft_strlen((char *)s) && s[start] != '\0' && i < leng)
	{
		dst[i] = (char)s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
