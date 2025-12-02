/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:48:13 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/20 09:32:25 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_rotation(t_stack *node, t_stack **stack)
{
	int	position;
	int	size;

	position = ft_node_position(node, *stack);
	size = ft_lstsize(*stack);
	if (position <= size / 2)
		return (position);
	else
		return (position - size);
}

static void	single_rotation_b(int moves_b, t_stack **stack_b)
{
	while (moves_b != 0)
	{
		if (moves_b > 0)
		{
			ft_rb(stack_b);
			moves_b--;
		}
		if (moves_b < 0)
		{
			ft_rrb(stack_b);
			moves_b++;
		}
	}
}

static void	single_rotation_a(int moves_a, t_stack **stack_a)
{
	while (moves_a != 0)
	{
		if (moves_a > 0)
		{
			ft_ra(stack_a);
			moves_a--;
		}
		if (moves_a < 0)
		{
			ft_rra(stack_a);
			moves_a++;
		}
	}
}

static void	multiple_rotation(int moves_b, int moves_a,
								t_stack **stack_a, t_stack **stack_b)
{
	while (moves_b > 0 && moves_a > 0)
	{
		ft_rr(stack_a, stack_b);
		moves_b--;
		moves_a--;
	}
	while (moves_b < 0 && moves_a < 0)
	{
		ft_rrr(stack_a, stack_b);
		moves_b++;
		moves_a++;
	}
	single_rotation_b(moves_b, stack_b);
	single_rotation_a(moves_a, stack_a);
}

void	rotate_and_push(t_stack *min, t_stack **stack_a, t_stack **stack_b)
{
	int	moves_b;
	int	moves_a;

	moves_b = cheapest_rotation(min, stack_b);
	moves_a = cheapest_rotation(min->target, stack_a);
	multiple_rotation(moves_b, moves_a, stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
