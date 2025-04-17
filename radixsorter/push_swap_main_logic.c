/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_logic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:24:57 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:17 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_stacks *stacks)
{
	stacks->size_a = get_stack_size(stacks->a);
	stacks->size_b = 0;
	if (is_sorted(stacks->a) || stacks->size_a <= 1)
		return ;
	if (stacks->size_a <= 5)
	{
		sort_small(stacks);
	}
	else
	{
		assign_indices(stacks);
		radix_sort(stacks);
	}
}
