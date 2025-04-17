/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:25:14 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:17 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while (max_index > 0 && (max_index >> bits) != 0)
	{
		bits++;
	}
	if (max_index > 0 && bits == 0)
		return (1);
	return (bits);
}

void	radix_sort(t_stacks *stacks)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_node	*current_a;

	size = stacks->size_a;
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current_a = stacks->a;
			if (((current_a->index >> i) & 1) == 0)
				pb(stacks);
			else
				ra(stacks);
			j++;
		}
		while (stacks->size_b != 0)
			pa(stacks);
		i++;
	}
}
