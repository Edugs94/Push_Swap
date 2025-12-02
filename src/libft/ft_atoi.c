/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:51:30 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/18 19:28:08 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr, char **matrix)
{
	int		sign;
	int		i;
	int		nbr;
	long	overflow;

	i = 0;
	nbr = 0;
	overflow = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		overflow = overflow * 10 + (nptr[i] - 48);
		if ((sign > 0 && overflow > INT_MAX)
			|| (sign < 0 && - overflow < INT_MIN))
			free_and_exit(2, matrix, NULL);
		i++;
	}
	return (nbr * sign);
}
