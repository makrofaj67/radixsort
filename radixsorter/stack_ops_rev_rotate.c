/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:25:25 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:17 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	second_last = last->prev;
	if (second_last)
		second_last->next = NULL;
	else
		(*stack)->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stacks *stacks)
{
	if (stacks->a && stacks->a->next)
	{
		reverse_rotate(&(stacks->a));
		ft_printf("rra\n");
	}
}

void	rrb(t_stacks *stacks)
{
	if (stacks->b && stacks->b->next)
	{
		reverse_rotate(&(stacks->b));
		ft_printf("rrb\n");
	}
}

void	rrr(t_stacks *stacks)
{
	bool	rotated;

	rotated = false;
	if (stacks->a && stacks->a->next)
	{
		reverse_rotate(&(stacks->a));
		rotated = true;
	}
	if (stacks->b && stacks->b->next)
	{
		reverse_rotate(&(stacks->b));
		rotated = true;
	}
	if (rotated)
		ft_printf("rrr\n");
}
