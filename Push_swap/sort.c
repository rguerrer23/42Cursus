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
	
}