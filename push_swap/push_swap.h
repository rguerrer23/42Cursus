/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:22:49 by rguerrer          #+#    #+#             */
/*   Updated: 2023/11/28 17:51:00 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

int					main(int ac, char **av);
void				ft_error(void);
int					ft_check_args(int ac, char **av);
void				move(t_stack **stack_a, t_stack **stack_b, int cost_a,
						int cost_b);
void				ft_sort(t_stack **stack_a, t_stack **stack_b,
						int stack_size);
void				cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				get_target_pos(t_stack **stack_a, t_stack **stack_b);
void				get_cost_a(t_stack **stack_a, t_stack **stack_b);
void				get_cost_b(t_stack **stack_b);
void				refresh_pos(t_stack **stack_a, t_stack **stack_b);
void				ft_free_stack(t_stack **stack);
int					is_sorted(t_stack **stack);
void				ft_get_index(t_stack **stack, int ac);
int					ft_stack_size(t_stack *stack);
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);
void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);
void				do_ra(t_stack **stack_a);
void				do_rra(t_stack **stack_a);
void				ft_sort(t_stack **stack_a, t_stack **stack_b,
						int stack_size);
void				ft_sort_three(t_stack **stack_a);
int					is_duplicate(t_stack *a);
void				do_rb(t_stack **stack_b);
void				do_rrb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);

#endif