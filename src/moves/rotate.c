/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:22:49 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/20 08:50:51 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ft_ra(t_stack **stack)
{
	ft_rotate(stack);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack)
{
	ft_rotate(stack);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_1, t_stack **stack_2)
{
	ft_rotate(stack_1);
	ft_rotate(stack_2);
	write(1, "rr\n", 3);
}
