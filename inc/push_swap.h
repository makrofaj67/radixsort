/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:08:06 by rakman            #+#    #+#             */
/*   Updated: 2025/04/16 15:55:18 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../argparser/argparser.h"
# include "../lib/ft_printf/printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
}			t_stacks;

void		push_swap(t_stacks *stacks);

void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);

void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

int			get_stack_size(t_node *stack);
bool		is_sorted(t_node *stack);
void		free_stacks(t_stacks *stacks);
int			find_min_index_pos(t_node *stack);

void		sort_small(t_stacks *stacks);

void		assign_indices(t_stacks *stacks);

void		radix_sort(t_stacks *stacks);

#endif
