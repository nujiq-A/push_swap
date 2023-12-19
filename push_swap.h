/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:39:36 by qang              #+#    #+#             */
/*   Updated: 2023/12/19 17:20:45 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	ft_free_stack(t_list *stack);
t_list	*ft_newval(int val);
void	push_smallest(t_list **stack_a, t_list **stack_b);

void	check_args(int ac, char **av);

bool	ft_sorted(t_list **stack_a, t_list **stack_b);
t_list	*ft_newval(int val);
void	ft_free_stack(t_list *stack);

void	ft_error(void);
void	ft_free_split(char **temp);
void	handle_string(int ac, char **av, t_list **stack_a);

#endif
