/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:37:43 by rakman            #+#    #+#             */
/*   Updated: 2025/04/16 15:28:27 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSER_H
# define ARGPARSER_H

# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

char				*ft_strdup(const char *s1);
int					ft_printf(const char *str, ...);
void				ft_free_split(char **arr);
void				ft_free_list(t_node *head);
void				print_error_and_cleanup(char **args, t_node *list);

int					count_total_words(int argc, char *argv[]);
char				**allocate_final_args(int total_words);
bool				fill_final_args(char **final_args, int argc, char *argv[]);
char				**parse_arguments(int argc, char *argv[]);

int					ft_count_words_split(const char *str);
char				*ft_word_alloc_and_copy(const char *s, int start, int end);
bool				perform_split(char **result, const char *s);
char				**ft_xsplit(const char *s);

bool				check_str_format(const char *str);
bool				str_to_long(const char *str, long *out_num);
bool				is_valid_int_str(const char *str, int *out_int_val);
bool				is_duplicate_in_list(t_node *head, int value);

t_node				*create_node(int value);
void				add_node_to_list(t_node **head, t_node *new_node);
bool				validate_and_populate(char **args, t_node **list_head);
void				print_list(t_node *head);

#endif
