/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:45:14 by qang              #+#    #+#             */
/*   Updated: 2023/12/19 17:22:38 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_SUCCESS);
}

void	ft_free_split(char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	handle_string(int ac, char **av, t_list **stack_a)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			temp = ft_split(av[i], ' ');
			j = 0;
			while (temp[j] != NULL)
			{
				ft_lstadd_back(stack_a, ft_newval(ft_atoi(temp[j])));
				j++;
			}
			ft_free_split(temp);
		}
		else
			ft_lstadd_back(stack_a, ft_newval(ft_atoi(av[i])));
		i++;
	}
}

void	radix(t_list **stack_a, t_list **stack_b);
void	ft_print_stack(t_list *stack);

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	// t_list	*temp1;
	// t_list	*temp2;
	
	if (ac == 1)
		return (0);
	check_args(ac, av);
	stack_a = ft_lstnew(NULL);
	stack_b = ft_lstnew(NULL);
	if (stack_a == NULL || stack_b == NULL)
		return (0);
	handle_string(ac, av, &stack_a);
	ft_print_stack(stack_a->next);
	radix(&stack_a->next, &stack_b->next);
	ft_print_stack(stack_a->next);
	// ft_print_stack(stack_a->next);
	// temp1 = stack_a->next;
	// temp2 = stack_b->next;
	// while (!ft_sorted(&temp1, &temp2))
	// 	push_smallest(&temp1, &temp2);
	// while (temp2 != NULL)
	// 	pa(&temp1, &temp2);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}

int	get_max_bit(t_list **stack_a)
{
	int		max_bit;
	int		temp;
	t_list	*temp_stack;

	max_bit = 0;
	temp_stack = *stack_a;
	temp = *(int *)(temp_stack->content);
	while (temp_stack != NULL)
	{
		if (temp < *(int *)(temp_stack->content))
			temp = *(int *)(temp_stack->content);
		temp_stack = temp_stack->next;	
	}
	while ((temp >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	int	max_bit;
	int	i;
	int	size;

	max_bit = get_max_bit(stack_a);
	i = 0;
	while (i < max_bit)
	{
		size = ft_lstsize(*stack_a);
		while (size-- > 0)
		{
			if (((*(int *)((*stack_a)->content) >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}

void	ft_print_stack(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp != NULL)
	{
		ft_printf("%d\n", *(int *)(temp->content));
		temp = temp->next;
	}
}