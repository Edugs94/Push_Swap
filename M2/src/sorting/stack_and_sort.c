/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_and_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:26:58 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/20 20:08:54 by edu-legion       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_min(t_stack **iteri, long *last, t_stack **min)
{
	while (*iteri)
	{
		if ((*iteri)->content > *last && (*iteri)->index == 0)
		{
			*min = *iteri;
			break ;
		}
		*iteri = (*iteri)->next;
	}
}

static void	add_index_aux(t_stack **iteri, long *last, t_stack **min)
{
	while (*iteri)
	{
		if ((*iteri)->content > *last && (*iteri)->content < (*min)->content
			&& (*iteri)->index == 0)
			*min = *iteri;
		*iteri = (*iteri)->next;
	}
}

static void	add_index(t_stack **stack, int size)
{
	int		i;
	long	last;
	t_stack	*min;
	t_stack	*iteri;

	i = 0;
	if (!stack || !*stack || size <= 0)
		return ;
	last = LONG_MIN;
	while (i < size)
	{
		iteri = *stack;
		min = NULL;
		get_min(&iteri, &last, &min);
		iteri = *stack;
		add_index_aux(&iteri, &last, &min);
		if (min)
		{
			min->index = i;
			last = min->content;
		}
		i++;
	}
}

static void	sort_a(t_stack **stack)
{
	t_stack	*min;

	min = *stack;
	while (min->index != 0)
		min = min-> next;
	while (ft_node_position(min, *stack) != 0)
	{
		if (cheapest_rotation(min, stack) > 0)
			ft_ra(stack);
		else
			ft_rra(stack);
	}
}

void	stack_and_sort(int *clean_data, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = create_stack(clean_data, size);
	add_index(&stack_a, size);
	stack_b = NULL;
	if (check_order(&stack_a) == 0)
	{
		ft_lstclear(&stack_a);
		free_and_exit(0, NULL, clean_data);
	}
	turk_algorithm(&stack_a, &stack_b, size);
	sort_a(&stack_a);
	ft_lstclear(&stack_a);
}
