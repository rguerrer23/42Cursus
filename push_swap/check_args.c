/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:30:20 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/21 16:09:41 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_duplicate(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp -> next;
		while (tmp2)
		{
			if (tmp -> value == tmp2 -> value)
				return (1);
			tmp2 = tmp2 -> next;
		}
		tmp = tmp -> next;
	}
	return (0);
}

int	ft_check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
