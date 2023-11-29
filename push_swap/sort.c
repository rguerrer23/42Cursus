/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:39:01 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/28 17:52:23 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack **stack_a)
{
	int		size;
	int		i;
	t_stack	*ptr;

	size = ft_stack_size(*stack_a);
	i = 0;
	ptr = *stack_a;
	while (i < size)
	{
		if (ptr->index == size - 1)
			break ;
		ptr = ptr->next;
		i++;
	}
	if (i < size / 2)
	{
		while ((*stack_a)->index != 0)
			do_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != 0)
			do_rra(stack_a);
	}
}

void	push_except_three(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
    int	limit;
    int	count;
    int	x;

    count = 0;
    limit = stack_size / 2;
    x = 0;
    while (x < stack_size && stack_size > 6 &&count < limit)
    {
        if ((*stack_a)->index <= limit)
        {
            do_pb(stack_a, stack_b);
            count++;
        }
        else
            do_ra(stack_a);
        x++;
    }
    while (count < stack_size - 3)
    {
        do_pb(stack_a, stack_b);
        count++;
    }
}

void	ft_sort_three(t_stack **stack_a)
{
	if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index < (*stack_a)->next->next->index)
	{
		do_rra(stack_a);
		do_sa(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index < (*stack_a)->next->next->index)
		do_sa(stack_a);
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		do_rra(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		do_ra(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		do_sa(stack_a);
		do_rra(stack_a);
	}
}

void   print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp_a = stack_a;
	t_stack *tmp_b = stack_b;

	printf("stack_a:\n");
	while (tmp_a)
	{
		printf("value: %d, index: %d, pos: %d, target_pos: %d, cost_a: %d, cost_b: %d\n", tmp_a->value, tmp_a->index, tmp_a->pos, tmp_a->target_pos, tmp_a->cost_a, tmp_a->cost_b);
		tmp_a = tmp_a->next;
	}
	printf("stack_b:\n");
	while (tmp_b)
	{
		printf("value: %d, index: %d, pos: %d, target_pos: %d, cost_a: %d, cost_b: %d\n", tmp_b->value, tmp_b->index, tmp_b->pos, tmp_b->target_pos, tmp_b->cost_a, tmp_b->cost_b);
		tmp_b = tmp_b->next;
	}
}

void	ft_sort_big(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	push_except_three(stack_a, stack_b, stack_size);
	if(!is_sorted(stack_a))
		ft_sort_three(stack_a);
	while (*stack_b)
	{
		refresh_pos(stack_a, stack_b);
		get_target_pos(stack_a, stack_b);
		get_cost_a(stack_a, stack_b);
		get_cost_b(stack_b);
		print_stack(*stack_a, *stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		sort_a(stack_a);
	print_stack(*stack_a, *stack_b);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(stack_a))
		do_sa(stack_a);
	else if (stack_size == 3 && !is_sorted(stack_a))
		ft_sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(stack_a))
		ft_sort_big(stack_a, stack_b, stack_size);
}
