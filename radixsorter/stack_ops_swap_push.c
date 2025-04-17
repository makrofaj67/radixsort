/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:25:36 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:04 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stacks *stacks)
{
	if (stacks->a && stacks->a->next)
	{
		swap(&(stacks->a));
		ft_printf("sa\n");
	}
}

void	sb(t_stacks *stacks)
{
	if (stacks->b && stacks->b->next)
	{
		swap(&(stacks->b));
		ft_printf("sb\n");
	}
}

void	ss(t_stacks *stacks)
{
	bool	swapped;

	swapped = false;
	if (stacks->a && stacks->a->next)
	{
		swap(&(stacks->a));
		swapped = true;
	}
	if (stacks->b && stacks->b->next)
	{
		swap(&(stacks->b));
		swapped = true;
	}
	if (swapped)
		ft_printf("ss\n");
}

void	pa(t_stacks *stacks)
{
	if (stacks->b)
	{
		push(&(stacks->b), &(stacks->a));
		stacks->size_a++;
		stacks->size_b--;
		ft_printf("pa\n");
	}
}

void	pb(t_stacks *stacks)
{
	if (stacks->a)
	{
		push(&(stacks->a), &(stacks->b));
		stacks->size_a--;
		stacks->size_b++;
		ft_printf("pb\n");
	}
}
