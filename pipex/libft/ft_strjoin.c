/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:30:18 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/02 18:10:57 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		x;
	int		y;

	x = 0;
	y = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (str != NULL)
	{
		while (s1[x])
			str[y++] = s1[x++];
		x = 0;
		while (s2[x])
			str[y++] = s2[x++];
		str[y] = '\0';
		return (str);
	}
	return (NULL);
}
