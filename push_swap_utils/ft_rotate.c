#include "../push_swap.h"

void  ra(t_list **stack_a, t_list **stack_b)
{
  t_list *temp1;
  t_list *temp2;

  if (*stack_a == NULL || (*stack_a)->next == NULL)
    return ;
  temp1 = *stack_a;
  *stack_a = (*stack_a)->next;
  temp2 = ft_lstlast(*stack_a);
  temp2->next = temp1;
  temp1->next = NULL;
}

void  rb(t_list **stack_a, t_list **stack_b)
{
  t_list *temp1;
  t_list *temp2;

  if (*stack_b == NULL || (*stack_b)->next == NULL)
    return ;
  temp1 = *stack_b;
  *stack_b = (*stack_b)->next;
  temp2 = ft_lstlast(*stack_b);
  temp2->next = temp1;
  temp1->next = NULL;
}

void  rr(t_list **stack_a, t_list **stack_b)
{
  ra(stack_a, stack_b);
  rb(stack_a, stack_b);
}