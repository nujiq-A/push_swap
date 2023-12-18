#include "../push_swap.h"

void  rra(t_list **stack_a)
{
  t_list *temp1;
  t_list *temp2;

  if (*stack_a == NULL || (*stack_a)->next == NULL)
    return ;
  temp1 = *stack_a;
  while(temp1->next->next != NULL)
    temp1 = temp1->next;
  temp2 = temp1->next;
  temp1->next = NULL;
  temp2->next = *stack_a;
  *stack_a = temp2;
  write(1, "rra\n", 4);
}

void  rrb(t_list **stack_b)
{
  t_list *temp1;
  t_list *temp2;

  if (*stack_b == NULL || (*stack_b)->next == NULL)
    return ;
  temp1 = *stack_b;
  while(temp1->next->next != NULL)
    temp1 = temp1->next;
  temp2 = temp1->next;
  temp1->next = NULL;
  temp2->next = *stack_b;
  *stack_b = temp2;
  write(1, "rrb\n", 4);
}

void  rrr(t_list **stack_a, t_list **stack_b)
{
  rra(stack_a);
  rrb(stack_b);
  write(1, "rrr\n", 4);
}