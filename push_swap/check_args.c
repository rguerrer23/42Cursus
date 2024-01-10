/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:30:20 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/09 18:04:40 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_str(char *str, int i, long *num)
{
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
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

int	ft_check_args_helper(int ac, char **arg, int should_clean)
{
	int		i;

	i = 1;
	if (should_clean == 1)
		i = 0;
	while (i < ac)
	{
		if (!ft_isint(arg[i]))
		{
			if (should_clean)
				ft_clean(arg);
			return (0);
		}
		i++;
	}
	if (should_clean)
		ft_clean(arg);
	return (1);
}

int	ft_check_args(int ac, char **av)
{
	char	**arg;
	int		should_clean;

	should_clean = 0;
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		if (arg == NULL)
			return (0);
		ac = ft_split_len(arg);
		should_clean = 1;
	}
	else
		arg = av;
	return (ft_check_args_helper(ac, arg, should_clean));
}
