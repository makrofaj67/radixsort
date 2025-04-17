/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap_push0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:25:43 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:17 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_node **stack)
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

void	push(t_node **from, t_node **to)
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
