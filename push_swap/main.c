/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:28:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/01/09 18:00:08 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks push_swap");
}

void	ft_clean(char **arg)
{
	int	x;

	x = 0;
	while (arg[x])
	{
		free(arg[x]);
		x++;
	}
	free(arg);
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

int	ft_fill_choice(t_stack **a, int ac, char **av, char **arg)
{
    if (ac == 2)
    {
        arg = ft_split(av[1], ' ');
        ac = ft_split_len(arg);
        ft_fill_stack(a, ac, arg, 0);
        ft_clean(arg);
    }
    else
        ft_fill_stack(a, ac, av, 1);
    return (ac);
}

int	main(int ac, char **av)
{
    t_stack	*a;
    t_stack	*b;
    char	**arg;

    atexit(ft_leaks);
    arg = NULL;
    a = NULL;
    b = NULL;
    if (ac < 2)
        return (0);
    if (!ft_check_args(ac, av))
        ft_error();
    ac = ft_fill_choice(&a, ac, av, arg);
    if (is_duplicate(a))
        ft_error();
    ft_get_index(&a, ft_stack_size(a));
    ft_sort(&a, &b, ft_stack_size(a));
    ft_free_stack(&a, &b);
    return (0);
}
