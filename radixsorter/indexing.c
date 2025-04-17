/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:24:51 by rakman            #+#    #+#             */
/*   Updated: 2025/04/17 08:26:17 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_integer_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*copy_stack_to_array(t_node *stack, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack && i < size)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

static int	find_index_in_array(int *sorted_arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indices(t_stacks *stacks)
{
	int		*temp_array;
	t_node	*current;
	int		index;
	int		size;

	size = stacks->size_a;
	if (size <= 1)
		return ;
	temp_array = copy_stack_to_array(stacks->a, size);
	if (!temp_array)
		return ;
	sort_integer_array(temp_array, size);
	current = stacks->a;
	while (current)
	{
		index = find_index_in_array(temp_array, size, current->value);
		current->index = index;
		current = current->next;
	}
	free(temp_array);
}
