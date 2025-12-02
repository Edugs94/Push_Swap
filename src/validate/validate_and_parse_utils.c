/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_parse_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:22:21 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/19 22:24:31 by edu-legion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*atoi_args(int size, char **matrix)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (size));
	if (arr == NULL)
		free_and_exit(2, matrix, NULL);
	while (i < size)
	{
		arr[i] = ft_atoi(matrix[i], matrix);
		i++;
	}
	return (arr);
}

void	check_chars(char *str, char *limit, char **matrix)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < limit[i])
			return ;
		else if (str[i] == limit[i])
			i++;
		else
			free_and_exit(2, matrix, NULL);
	}
}
