/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:28:23 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/21 18:27:23 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cost;
	int		stack_size;

	tmp = *stack_b;
	stack_size = ft_stack_size(*stack_a) / 2;
	while (tmp)
	{
		if (tmp->target_pos < stack_size)
			tmp->cost_a = tmp->target_pos;
		else
			tmp->cost_a = ft_stack_size(*stack_a) - tmp->target_pos;
		tmp = tmp->next;
	}
}

void	get_cost_b(t_stack **stack_b)
{
	t_stack	*tmp;
	int		stack_size;

	tmp = *stack_b;
	stack_size = ft_stack_size(*stack_b) / 2;
	while (tmp)
	{
		if (tmp->pos < stack_size)
			tmp->cost_b = tmp->pos;
		else
			tmp->cost_b = ft_stack_size(*stack_b) - tmp->pos;
		tmp = tmp->next;
	}
}

int	get_target(int index, t_stack **stack)
{
	t_stack	*tmp;
	int		target;
	int		min_diff;
	int		diff;

	target = 0;
	min_diff = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		diff = tmp->index - index;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target);
}

void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		target;

	target = 0;
	tmp = *stack_b;
	while (tmp)
	{
		target = get_target(tmp->index, stack_a);
		tmp->target_pos = target;
		tmp = tmp->next;
	}
}

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min_cost;
	int		cost;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	min_cost = INT_MAX;
	while (tmp)
	{
		cost = tmp->cost_a + tmp->cost_b;
		if (cost < min_cost)
		{
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
			min_cost = cost;
			*stack_a = tmp;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}
