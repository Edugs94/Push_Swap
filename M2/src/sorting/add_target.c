/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:47:41 by edu-legion        #+#    #+#             */
/*   Updated: 2025/11/20 09:19:31 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	add_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*iter_b;
	t_stack	*iter_a;
	long	best_idx;

	iter_b = *stack_b;
	while (iter_b)
	{
		best_idx = LONG_MAX;
		iter_a = *stack_a;
		iter_b->target = get_min(*stack_a);
		while (iter_a)
		{
			if (iter_a->index > iter_b->index && iter_a->index < best_idx)
			{
				best_idx = iter_a->index;
				iter_b->target = iter_a;
			}
			iter_a = iter_a->next;
		}
		iter_b = iter_b->next;
	}
}
