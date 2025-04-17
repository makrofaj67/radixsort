/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser_validate_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:56:24 by rakman            #+#    #+#             */
/*   Updated: 2025/04/16 11:04:12 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser.h"

bool	is_duplicate_in_list(t_node *head, int value)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->value == value)
			return (true);
		current = current->next;
		if (current == head)
			break ;
	}
	return (false);
}

bool	str_to_long(const char *str, long *out_num)
{
	char	*endptr;
	long	num;

	errno = 0;
	num = strtol(str, &endptr, 10);
	if (*endptr != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	*out_num = num;
	return (true);
}

bool	check_str_format(const char *str)
{
	int	i;
	int	digit_found;

	i = 0;
	digit_found = 0;
	if (str == NULL || str[0] == '\0')
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		digit_found = 1;
		i++;
	}
	return (digit_found);
}

bool	is_valid_int_str(const char *str, int *out_int_val)
{
	long	num;

	if (!check_str_format(str))
		return (false);
	if (!str_to_long(str, &num))
		return (false);
	if (num < INT_MIN || num > INT_MAX)
		return (false);
	*out_int_val = (int)num;
	return (true);
}
