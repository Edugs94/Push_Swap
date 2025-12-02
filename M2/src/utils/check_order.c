/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:19:26 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/26 11:51:18 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack **stack)
{
	t_stack	*iteri;

	iteri = *stack;
	while (iteri->next)
	{
		if (iteri->index < iteri->next->index)
			iteri = iteri->next;
		else
			return (1);
	}
	return (0);
}
