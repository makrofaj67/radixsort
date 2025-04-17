/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:20:47 by rakman            #+#    #+#             */
/*   Updated: 2025/04/16 15:49:10 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser/argparser.h"
#include "inc/push_swap.h"

int	main(int argc, char *argv[])
{
	char		**final_args;
	t_stacks	stacks;
	bool		is_valid;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.size_a = 0;
	stacks.size_b = 0;
	if (argc < 2)
		return (0);
	final_args = parse_arguments(argc, argv);
	if (!final_args)
		print_error_and_cleanup(NULL, NULL);
	is_valid = validate_and_populate(final_args, &(stacks.a));
	if (!is_valid)
		print_error_and_cleanup(final_args, stacks.a);
	ft_free_split(final_args);
	push_swap(&stacks);
	free_stacks(&stacks);
	return (0);
}
