/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:46:45 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/15 17:46:45 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_get_index(t_stack **stack, int ac)
{
	t_stack	*ptr;
	t_stack	*biggest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
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
			biggest->index = stack_size;
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