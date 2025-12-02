/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:19:59 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/20 09:12:55 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

t_stack	*create_stack(int *int_arr, int size)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	if (size <= 0)
		return (NULL);
	i = 0;
	stack = ft_lstnew(int_arr[i]);
	i++;
	while (i < size)
	{
		new_node = ft_lstnew(int_arr[i]);
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}
