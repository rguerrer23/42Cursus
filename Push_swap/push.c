/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:08:18 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/21 16:10:02 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	write(1, "pa\n", 3);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	write(1, "pb\n", 3);
}
