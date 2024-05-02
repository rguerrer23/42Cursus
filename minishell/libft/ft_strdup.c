/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:54:24 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/02 18:10:48 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*des;
	int			x;
	int			y;

	x = ft_strlen(s1);
	des = (char *)malloc((x) * sizeof(char) + 1);
	y = 0;
	if (des != NULL)
	{
		while (s1[y] != '\0')
		{
			des[y] = s1[y];
			y++;
		}
		des[y] = '\0';
		return (des);
	}
	return (NULL);
}
