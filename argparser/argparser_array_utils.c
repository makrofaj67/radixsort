/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser_array_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:51:06 by rakman            #+#    #+#             */
/*   Updated: 2025/04/16 11:25:45 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser.h"

char	**allocate_final_args(int total_words)
{
	char	**final_args;

	final_args = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (!final_args)
		return (NULL);
	return (final_args);
}

int	count_total_words(int argc, char *argv[])
{
	int	total_words;
	int	i;

	total_words = 0;
	i = 1;
	while (i < argc)
	{
		total_words += ft_count_words_split(argv[i]);
		i++;
	}
	return (total_words);
}

static bool	append_split_to_final_strdup(char **final_args, int *current_idx,
		char *arg)
{
	char	**temp_split;
	char	*dup_str;
	int		j;

	temp_split = ft_xsplit(arg);
	if (!temp_split)
		return (false);
	j = 0;
	while (temp_split[j])
	{
		dup_str = ft_strdup(temp_split[j]);
		if (!dup_str)
		{
			ft_free_split(temp_split);
			return (false);
		}
		final_args[*current_idx] = dup_str;
		(*current_idx)++;
		j++;
	}
	ft_free_split(temp_split);
	return (true);
}

bool	fill_final_args(char **final_args, int argc, char *argv[])
{
	int	current_index;
	int	i;

	current_index = 0;
	i = 1;
	while (i < argc)
	{
		if (!append_split_to_final_strdup(final_args, &current_index, argv[i]))
		{
			ft_free_split(final_args);
			return (false);
		}
		i++;
	}
	final_args[current_index] = NULL;
	return (true);
}
