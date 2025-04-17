/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:25:49 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:18 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	free_stacks(t_stacks *stacks)
{
	ft_free_list(stacks->a);
	ft_free_list(stacks->b);
	stacks->a = NULL;
	stacks->b = NULL;
}

int	find_min_index_pos(t_node *stack)
{
	int	min_idx;
	int	min_pos;
	int	curr_pos;

	if (!stack)
		return (-1);
	min_idx = stack->index;
	min_pos = 0;
	curr_pos = 0;
	while (stack)
	{
		if (stack->index < min_idx)
		{
			min_idx = stack->index;
			min_pos = curr_pos;
		}
		stack = stack->next;
		curr_pos++;
	}
	return (min_pos);
}
