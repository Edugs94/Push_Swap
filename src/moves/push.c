/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:20:31 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/20 08:51:59 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*ptr;

	if (!*stack_from)
		return ;
	ptr = *stack_from;
	*stack_from = (*stack_from)->next;
	if (!*stack_to)
	{
		*stack_to = ptr;
		(*stack_to)->next = NULL;
	}
	else
	{
		ptr->next = *stack_to;
		*stack_to = ptr;
	}
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
