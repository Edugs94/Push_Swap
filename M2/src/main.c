/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:49:30 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/20 08:47:38 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*clean_data;
	int	size;

	clean_data = validate_and_parse(argc, argv, &size);
	stack_and_sort(clean_data, size);
	free(clean_data);
	return (0);
}
