#include "../push_swap.h"

void	sa(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "sa\n", 3);
}
void	sb(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
	write(1, "ss\n", 3);
}