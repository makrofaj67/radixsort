/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakman <rakman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:46:30 by rakman            #+#    #+#             */
/*   Updated: 2025/04/16 10:50:41 by rakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparser.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_count_words_split(const char *str)
{
	int	count;
	int	i;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (str && str[i])
	{
		if (!is_whitespace(str[i]) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_whitespace(str[i]))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*ft_word_alloc_and_copy(const char *s, int start, int end)
{
	char	*word;
	int		i;
	int		len;

	len = end - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

bool	perform_split(char **result, const char *s)
{
	int	i;
	int	j;
	int	word_start;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		while (s[i] && is_whitespace(s[i]))
			i++;
		if (s[i])
		{
			word_start = i;
			while (s[i] && !is_whitespace(s[i]))
				i++;
			result[j] = ft_word_alloc_and_copy(s, word_start, i);
			if (!result[j])
			{
				return (false);
			}
			j++;
		}
	}
	result[j] = NULL;
	return (true);
}

char	**ft_xsplit(const char *s)
{
	char	**result;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words_split(s);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	if (!perform_split(result, s))
		return (NULL);
	return (result);
}
