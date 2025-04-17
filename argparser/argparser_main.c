/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:40:23 by rakman            #+#    #+#             */
/*   Updated: 2025/04/16 11:31:00 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser.h"

bool	validate_and_populate(char **args, t_node **list_head)
{
	int		i;
	int		num_val;
	t_node	*new_node;

	i = 0;
	*list_head = NULL;
	while (args && args[i])
	{
		if (!is_valid_int_str(args[i], &num_val))
			return (false);
		if (is_duplicate_in_list(*list_head, num_val))
			return (false);
		new_node = create_node(num_val);
		if (!new_node)
			return (false);
		add_node_to_list(list_head, new_node);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}

char	**parse_arguments(int argc, char *argv[])
{
	char	**final_args;
	int		total_words;

	total_words = count_total_words(argc, argv);
	if (total_words == 0)
		return (NULL);
	final_args = allocate_final_args(total_words);
	if (!final_args)
		return (NULL);
	if (!fill_final_args(final_args, argc, argv))
		return (NULL);
	return (final_args);
}
