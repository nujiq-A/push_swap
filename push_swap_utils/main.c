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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp1;
	t_list	*temp2;
	int j;

	if (ac == 1)
		return (0);
	check_args(ac, av);
	stack_a = ft_lstnew(NULL);
	stack_b = ft_lstnew(NULL);
	if (stack_a == NULL || stack_b == NULL)
		return (0);
	handle_string(ac, av, &stack_a);
	temp1 = stack_a->next;
	temp2 = stack_b->next;
	j = 0;
	while (!ft_sorted(&temp1, &temp2))
	{
		push_smallest(&temp1, &temp2);
		j++;
	}
	while (temp2 != NULL)
		pa(&temp1, &temp2);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
