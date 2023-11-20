/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:22:49 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/15 11:22:49 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"
# include "limish.h"

typedef struct	s_stack
{
	int		value;
	int		index;
	int		pos;
	int		target_pos;
	int		cost_a;
	int		cost_b;
	struct s_stack	*next;
}				t_stack;
