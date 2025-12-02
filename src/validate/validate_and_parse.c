/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:11:05 by egalindo          #+#    #+#             */
/*   Updated: 2025/12/02 18:49:52 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_validator(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = 0;
		if (matrix[i][j] == '-')
			j++;
		while (matrix[i][j])
		{
			if (matrix[i][j] >= '0' && matrix[i][j] <= '9')
				j++;
			else
				free_and_exit(2, matrix, NULL);
		}
		i++;
	}
	return (i);
}

static char	**remove_first_element(int argc, char **argv)
{
	int		i;
	char	**matrix;

	i = 1;
	matrix = malloc (sizeof(char *) * ((argc - 1) + 1));
	while (argv[i])
	{
		matrix[i - 1] = ft_strdup(argv[i]);
		if (!matrix[i - 1])
			free_and_exit(2, matrix, NULL);
		i++;
	}
	matrix[i - 1] = NULL;
	return (matrix);
}

static void	dupe_detector(int *arr, char **matrix, int size)
{
	int	i;
	int	j;
	int	reps;

	i = 0;
	reps = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == arr[j])
				reps++;
			j++;
		}
		i++;
	}
	if (reps != size)
		free_and_exit(3, matrix, arr);
}

static void	check_empty_str(char *str)
{
	int	len;
	int	i;
	int	count;

	i = 0;
	count = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	if (count == len)
		return (free_and_exit(1, NULL, NULL));
}

int	*validate_and_parse(int argc, char **argv, int *size)
{
	int		i;
	int		*int_arr;
	char	**matrix;

	i = 1;
	if (argc <= 1)
		free_and_exit(1, NULL, NULL);
	if (argc == 2)
	{
		check_empty_str(argv[1]);
		matrix = ft_split(argv[1], ' ');
	}
	else
		matrix = remove_first_element(argc, argv);
	*size = num_validator(matrix);
	int_arr = atoi_args(*size, matrix);
	dupe_detector(int_arr, matrix, *size);
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (int_arr);
}
