/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:19:40 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/28 17:48:31 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	write(1, "ra\n", 3);
}

void	do_rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		while (last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	write(1, "rra\n", 4);
}

void	do_rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	write(1, "rb\n", 3);
}

void	do_rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		while (last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	write(1, "rrb\n", 4);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	write(1, "rr\n", 3);
}
