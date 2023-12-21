/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:30:20 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/21 12:26:06 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isdigit_str(char *str, int i, long *num)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		*num = *num * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

int	ft_check_sign(char *str, int *i, int *sign)
{
	if (*str == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else
		*sign = 1;
	if (str[*i] == '\0')
		return (0);
	return (1);
}

int	ft_isint(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	if (!str || !*str)
		return (0);
	if (!ft_check_sign(str, &i, &sign))
		return (0);
	if (!ft_isdigit_str(str, i, &num))
		return (0);
	num = num * sign;
	if ((sign > 0 && num > INT_MAX) || (sign < 0 && num < INT_MIN))
		return (0);
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	int		i;
	int		j;
	char	**arg;

	i = 1;
	j = 0;
	while (i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (arg == NULL)
			return (0);
		while (arg[j])
		{
			if (!ft_isint(arg[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
