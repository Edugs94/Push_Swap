/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:22:42 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/20 09:19:03 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack **stack)
{
	t_stack	*iteri;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	iteri = *stack;
	last = *stack;
	while (iteri->next)
		iteri = iteri->next;
	while (last->next != iteri)
		last = last->next;
	last->next = NULL;
	iteri->next = *stack;
	*stack = iteri;
}

void	ft_rra(t_stack **stack)
{
	ft_rrotate(stack);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack)
{
	ft_rrotate(stack);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_1, t_stack **stack_2)
{
	ft_rrotate(stack_1);
	ft_rrotate(stack_2);
	write(1, "rrr\n", 4);
}
