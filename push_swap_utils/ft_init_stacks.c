/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:26:13 by qang              #+#    #+#             */
/*   Updated: 2023/12/19 17:21:05 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp->content);
		free(temp);
	}
}

t_list	*ft_newval(int val)
{
	t_list	*temp;
	int		*temp_val;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	temp_val = (int *)malloc(sizeof(int));
	if (temp_val == NULL)
		return (NULL);
	*temp_val = val;
	temp->content = temp_val;
	temp->next = NULL;
	return (temp);
}

static bool	ft_b_sorted(t_list **stack_b)
{
	t_list	*temp;
	int		prev;
	int		curr;

	temp = *stack_b;
	if (temp == NULL)
		return (true);
	prev = *(int *)temp->content;
	temp = temp->next;
	while (temp != NULL)
	{
		curr = *(int *)temp->content;
		if (prev < curr)
			return (false);
		prev = curr;
		temp = temp->next;
	}
	return (true);
}

bool	ft_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		prev;
	int		curr;

	temp = *stack_a;
	if (temp == NULL)
		return (true);
	prev = *(int *)temp->content;
	temp = temp->next;
	while (temp != NULL)
	{
		curr = *(int *)temp->content;
		if (prev > curr)
			return (false);
		prev = curr;
		temp = temp->next;
	}
	return (ft_b_sorted(stack_b));
}
