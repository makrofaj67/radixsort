/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:25:19 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:17 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_two(t_stacks *stacks)
{
	if (stacks->a->value > stacks->a->next->value)
		sa(stacks);
}

static void	sort_three(t_stacks *stacks)
{
	t_node	*h;
	t_node	*m;
	t_node	*t;

	h = stacks->a;
	if (!h || !h->next || !h->next->next || is_sorted(h))
		return ;
	m = h->next;
	t = m->next;
	if (h->value > m->value && m->value < t->value && h->value < t->value)
		sa(stacks);
	else if (h->value > m->value && m->value > t->value)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (h->value > m->value && m->value < t->value && h->value > t->value)
		ra(stacks);
	else if (h->value < m->value && m->value > t->value && h->value < t->value)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (h->value < m->value && m->value > t->value && h->value > t->value)
		rra(stacks);
}

static void	bring_min_to_top(t_stacks *stacks)
{
	int	min_pos;
	int	size;

	size = stacks->size_a;
	min_pos = find_min_index_pos(stacks->a);
	if (min_pos < 0)
		return ;
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(stacks);
	}
	else
	{
		while (min_pos++ < size)
			rra(stacks);
	}
}

static void	sort_four_five(t_stacks *stacks)
{
	while (stacks->size_a > 3)
	{
		bring_min_to_top(stacks);
		pb(stacks);
	}
	sort_three(stacks);
	while (stacks->size_b > 0)
	{
		pa(stacks);
	}
}

void	sort_small(t_stacks *stacks)
{
	assign_indices(stacks);
	if (stacks->size_a == 2)
		sort_two(stacks);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a <= 5)
		sort_four_five(stacks);
}
