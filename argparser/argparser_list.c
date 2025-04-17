/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:04:36 by rakman            #+#    #+#             */
/*   Updated: 2025/04/16 11:07:46 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser.h"

void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
		if (current == head)
			break ;
	}
}

void	ft_free_list(t_node *head)
{
	t_node	*current;
	t_node	*next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		if (current == head)
			break ;
	}
}

void	add_node_to_list(t_node **head, t_node *new_node)
{
	t_node	*tail;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		tail = *head;
		while (tail->next != NULL && tail->next != *head)
			tail = tail->next;
		tail->next = new_node;
		new_node->prev = tail;
	}
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
