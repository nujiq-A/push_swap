/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:39:52 by qang              #+#    #+#             */
/*   Updated: 2023/12/19 17:20:38 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_indexofsmallest(t_list *stack)
{
	int	smallest;
	int	index;
	int	i;

	i = 0;
	index = 0;
	smallest = INT_MAX;
	while (stack)
	{
		if (*(int *)stack->content < smallest)
		{
			smallest = *(int *)stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

void	push_smallest(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	size;

	size = ft_lstsize(*stack_a);
	index = ft_indexofsmallest(*stack_a);
	if (index < size / 2)
	{
		while (index--)
			ra(stack_a);
	}
	else
	{
		index = size - index;
		while (index--)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}
