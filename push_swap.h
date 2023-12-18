#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>

void  sa(t_list **stack_a, t_list **stack_b);
void  sb(t_list **stack_a, t_list **stack_b);
void  ss(t_list **stack_a, t_list **stack_b);
void  pa(t_list **stack_a, t_list **stack_b);
void  pb(t_list **stack_a, t_list **stack_b);
void  ra(t_list **stack_a);
void  rb(t_list **stack_b);
void  rr(t_list **stack_a, t_list **stack_b);
void  rra(t_list **stack_a);
void  rrb(t_list **stack_b);
void  rrr(t_list **stack_a, t_list **stack_b);

void  ft_free_stack(t_list *stack);
t_list *ft_newval(int val);
void  push_largest(t_list **stack_a, t_list **stack_b);
void  push_smallest(t_list **stack_a, t_list **stack_b);

#endif
