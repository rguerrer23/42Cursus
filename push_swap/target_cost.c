/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:28:23 by rguerrer          #+#    #+#             */
/*   Updated: 2023/12/20 16:49:20 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		stack_size_a;

	tmp_b = *stack_b;
	tmp_a = *stack_a;
	stack_size_a = ft_stack_size(tmp_a);
	while (tmp_b)
	{
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > stack_size_a / 2)
			tmp_b->cost_a = (stack_size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	get_cost_b(t_stack **stack_b)
{
	t_stack	*tmp;
	int		stack_size;

	tmp = *stack_b;
	stack_size = ft_stack_size(tmp);
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > stack_size / 2)
			tmp->cost_b = (stack_size - tmp->pos) * -1;
		tmp = tmp->next;
	}
}

int	get_target(int index, t_stack **stack)
{
	t_stack		*tmp;
	t_target	t;

	t.target = -1;
	t.min_diff = INT_MAX;
	t.min_index = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index - index >= 0 && tmp->index - index < t.min_diff)
		{
			t.min_diff = tmp->index - index;
			t.target = tmp->pos;
		}
		if (tmp->index < t.min_index)
		{
			t.min_index = tmp->index;
			t.min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (t.target == -1)
		t.target = t.min_pos;
	return (t.target);
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
		cost = (abs)(tmp->cost_a) + (abs)(tmp->cost_b);
		if (cost < min_cost)
		{
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
			min_cost = cost;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}
