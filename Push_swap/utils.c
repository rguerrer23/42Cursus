/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:46:45 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/21 17:28:37 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_index(t_stack **stack, int ac)
{
	t_stack	*ptr;
	t_stack	*biggest;
	int		value;

	while (--ac > 0)
	{
		ptr = stack;
		biggest = NULL;
		value = INT_MIN;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				biggest = ptr;
				ptr = ptr->next;
			}
			else
				ptr = ptr->next;
		}
		if (biggest != NULL)
			biggest->index = ac;
	}
}

int	ft_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*ptr;

	ptr = *stack;
	while (ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	refresh_pos(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	i = 1;
	while (*stack_a)
	{
		(*stack_a)->pos = i;
		(*stack_a) = (*stack_b)->next;
		i++;
	}
	i = 1;
	while (*stack_b)
	{
		(*stack_b)->pos = i;
		(*stack_b) = (*stack_b)->next;
		i++;
	}
}
