/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 07:12:55 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/18 20:08:24 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	words_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	word_len(char const *s, char c, size_t *index)
{
	size_t	start;
	size_t	end;

	start = *index;
	while (s[start] == c)
		start++;
	end = start;
	while (s[end] && s[end] != c)
		end++;
	*index = end;
	return (end - start);
}

static char	**free_matrix(char **matrix, size_t i)
{
	while (i > 0)
	{
		i--;
		free(matrix[i]);
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	index;
	size_t	w_count;
	size_t	len;

	if (!s)
		return (NULL);
	w_count = words_count(s, c);
	matrix = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	index = 0;
	while (i < w_count)
	{
		len = word_len(s, c, &index);
		matrix[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!matrix[i])
			return (free_matrix(matrix, i));
		ft_strlcpy(matrix[i], s + (index - len), len + 1);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
