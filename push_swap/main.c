/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:28:32 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/21 12:53:47 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

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

void	ft_fill_stack(t_stack **a, int ac, char **av, int i)
{
	t_stack	*tmp;
	t_stack	*last;

	last = NULL;
	while (i < ac)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			ft_error();
		tmp->value = ft_atoi(av[i]);
		tmp->index = 0;
		tmp->pos = i - 1;
		tmp->target_pos = 0;
		tmp->cost_a = 0;
		tmp->cost_b = 0;
		tmp->next = NULL;
		if (last)
			last->next = tmp;
		else
			*a = tmp;
		last = tmp;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**arg;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!ft_check_args(ac, av))
		ft_error();
	if (ac == 2)
	{
		arg = ft_split(av[1], ' ');
		ac = ft_split_len(arg);
		ft_fill_stack(&a, ac, arg, 0);
	}
	else
		ft_fill_stack(&a, ac, av, 1);
	if (is_duplicate(a))
		ft_error();
	ft_get_index(&a, ft_stack_size(a));
	ft_sort(&a, &b, ft_stack_size(a));
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
