/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:06:39 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/20 09:21:53 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_top_cost(t_stack **stack)
{
	int		i;
	t_stack	*iteri;

	iteri = *stack;
	i = 0;
	while (iteri)
	{
		if (ft_node_position(iteri, *stack) <= ft_lstsize(*stack) / 2)
			iteri->top_cost = i;
		else
			iteri->top_cost = ft_lstsize(*stack) - i;
		iteri = iteri->next;
		i++;
	}
}

void	add_total_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*iteri_a;
	t_stack	*iteri_b;

	iteri_b = *stack_b;
	while (iteri_b)
	{
		i = 0;
		iteri_a = *stack_a;
		while (iteri_a)
		{
			if (iteri_b->target == iteri_a)
			{
				if (ft_node_position(iteri_a, *stack_a)
					<= ft_lstsize(*stack_a) / 2)
					iteri_b->target_cost = i;
				else
					iteri_b->target_cost = ft_lstsize(*stack_a) - i;
				iteri_b->total_cost = iteri_b->target_cost + iteri_b->top_cost;
			}
			iteri_a = iteri_a->next;
			i++;
		}
		iteri_b = iteri_b->next;
	}
}

static t_stack	*get_min_cost(t_stack **stack)
{
	t_stack	*iteri;
	t_stack	*min;

	iteri = *stack;
	min = iteri;
	while (iteri)
	{
		if (iteri->total_cost < min->total_cost)
			min = iteri;
		iteri = iteri->next;
	}
	return (min);
}

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	t_stack	*min;

	i = 0;
	while (i++ < size - 3)
		ft_pb(stack_a, stack_b);
	sort_3_a(stack_a);
	i = 0;
	while (i++ < size - 3)
	{
		add_target(stack_a, stack_b);
		add_top_cost(stack_b);
		add_total_cost(stack_a, stack_b);
		min = get_min_cost(stack_b);
		rotate_and_push(min, stack_a, stack_b);
	}
}
