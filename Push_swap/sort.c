/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:39:01 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/15 11:39:01 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_except_three(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int x;
	int limit;

	count = 0;
	limit = stack_size / 2;
	while(x < limit)
	{
		if((*stack_a)->index < limit)
		{
			do_pb(stack_a, stack_b);
			count++;
		}
		else
			do_ra(stack_a);
	}
	while(count < stack_size - 3)
	{
		do_pb(stack_a, stack_b);
		count++;
	}
}

void	ft_sort_big(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	push_except_three(stack_a, stack_b, stack_size);
	ft_sort_three(stack_a);
}

void	ft_sort_three(t_stack **stack_a)
{
	if((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->index < (*stack_a)->next->next->index)
	{
		do_rra(stack_a);
		do_sa(stack_a);
	}
	else if((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index < (*stack_a)->next->next->index)
		do_sa(stack_a);
	else if((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->index > (*stack_a)->next->next->index)
		do_rra(stack_a);
	else if((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index > (*stack_a)->next->next->index)
		do_ra(stack_a);
	else if((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index > (*stack_a)->next->next->index)
	{
		do_sa(stack_a);
		do_rra(stack_a);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if(stack_size == 2 && !is_sorted(stack_a))
		do_sa(stack_a);
	else if(stack_size == 3)
		ft_sort_three(stack_a);
	else if(stack_size > 3 && !is_sorted(stack_a))
		ft_sort_big(stack_a, stack_b, stack_size);
}