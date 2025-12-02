/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu-legion <edu-legion@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:32:51 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/19 16:10:37 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_a(t_stack **stack)
{
	int	i1;
	int	i2;
	int	i3;

	if (ft_lstsize(*stack) != 3)
		return ;
	i1 = (*stack)->index;
	i2 = (*stack)->next->index;
	i3 = (*stack)->next->next->index;
	if (i1 > i2 && i2 < i3 && i1 < i3)
		ft_sa(stack);
	if (i1 > i2 && i2 < i3 && i1 > i3)
		ft_ra(stack);
	if (i1 < i2 && i2 > i3)
	{
		ft_rra(stack);
		if (i1 < i3)
			ft_sa(stack);
	}
	if (i1 > i2 && i2 > i3)
	{
		ft_ra(stack);
		ft_sa(stack);
	}
}

void	sort_3_b(t_stack **stack)
{
	int	i1;
	int	i2;
	int	i3;

	if (ft_lstsize(*stack) != 3)
		return ;
	i1 = (*stack)->index;
	i2 = (*stack)->next->index;
	i3 = (*stack)->next->next->index;
	if (i1 > i2 && i2 < i3 && i1 < i3)
		ft_sb(stack);
	if (i1 > i2 && i2 < i3 && i1 > i3)
		ft_rb(stack);
	if (i1 < i2 && i2 > i3)
	{
		ft_rrb(stack);
		if (i1 < i3)
			ft_sb(stack);
	}
	if (i1 > i2 && i2 > i3)
	{
		ft_rb(stack);
		ft_sb(stack);
	}
}
