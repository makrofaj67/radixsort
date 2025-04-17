/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/04/16 15:56:23 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	first->next = third;
	if (third)
		third->prev = first;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}

static void	push(t_node **from, t_node **to)
{
	t_node	*node_to_move;

	if (!from || !*from)
		return ;
	node_to_move = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	node_to_move->prev = NULL;
	if (!*to)
	{
		*to = node_to_move;
		node_to_move->next = NULL;
	}
	else
	{
		node_to_move->next = *to;
		(*to)->prev = node_to_move;
		*to = node_to_move;
	}
}

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
