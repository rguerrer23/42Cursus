/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:10:53 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/28 11:10:53 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		do_rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		do_rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rotate_b(t_stack **stack_b, int *cost_b)
{
	if (*cost_b < 0)
	{
		while (*cost_b < 0)
		{
			do_rrb(stack_b);
			(*cost_b)++;
		}
	}
	else
	{
		while (*cost_b > 0)
		{
			do_rb(stack_b);
			(*cost_b)--;
		}
	}
}

void	rotate_a(t_stack **stack_a, int *cost_a)
{
	if (*cost_a < 0)
	{
		while (*cost_a < 0)
		{
			do_rra(stack_a);
			(*cost_a)++;
		}
	}
	else
	{
		while (*cost_a > 0)
		{
			do_ra(stack_a);
			(*cost_a)--;
		}
	}
}

void  move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if(cost_a < 0 && cost_b < 0)
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if(cost_a > 0 && cost_b > 0)
		reverse_both(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b);
}