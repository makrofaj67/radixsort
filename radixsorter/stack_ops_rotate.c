/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:25:30 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:18 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stacks *stacks)
{
	if (stacks->a && stacks->a->next)
	{
		rotate(&(stacks->a));
		ft_printf("ra\n");
	}
}

void	rb(t_stacks *stacks)
{
	if (stacks->b && stacks->b->next)
	{
		rotate(&(stacks->b));
		ft_printf("rb\n");
	}
}

void	rr(t_stacks *stacks)
{
	bool	rotated;

	rotated = false;
	if (stacks->a && stacks->a->next)
	{
		rotate(&(stacks->a));
		rotated = true;
	}
	if (stacks->b && stacks->b->next)
	{
		rotate(&(stacks->b));
		rotated = true;
	}
	if (rotated)
		ft_printf("rr\n");
}
