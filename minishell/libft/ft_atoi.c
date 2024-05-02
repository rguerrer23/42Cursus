/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:55:39 by rguerrer          #+#    #+#             */
/*   Updated: 2023/05/02 18:05:52 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	num;
	int	signo;

	x = 0;
	num = 0;
	signo = 1;
	while ((str[x] == ' ') || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-')
	{
		signo = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] != '\0' && (str[x] >= '0' && str[x] <= '9'))
	{
		num *= 10;
		num += str[x] - '0';
		x++;
	}
	return (num * signo);
}
