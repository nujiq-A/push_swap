#include "../push_swap.h"

void  ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
  t_list *temp;

  temp = stack_a;
  printf("Stack A: ");
  while (temp != NULL)
  {
    printf("%d ", *(int *)temp->content);
    temp = temp->next;
  }
  printf("\n");
  temp = stack_b;
  printf("Stack B: ");
  while (temp != NULL)
  {
    printf("%d ", *(int *)temp->content);
    temp = temp->next;
  }
  printf("\n");
}

t_list *ft_newval(int val)
{
	t_list *temp;
	int *temp_val;

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

int main(int ac, char **av)
{
	t_list *stack_a;
  t_list *stack_b;
  int i;
  t_list *temp;

	if (ac < 2)
		return 0;
	stack_a = ft_lstnew(NULL);
  stack_b = ft_lstnew(NULL);
  if (stack_a == NULL || stack_b == NULL)
    return 0;
  i = 1;
	while (i < ac)
	{
		temp = ft_newval(ft_atoi(av[i]));
		if (temp == NULL)
			return (0);
		ft_lstadd_back(&stack_a, temp);
		i++;
	}
  t_list *temp1 = stack_a->next;
  t_list *temp2 = stack_b->next;
  printf("BEginning:\n");
  ft_print_stacks(temp1, temp2);
  printf("\n");

  sa(&temp1, &temp2);
  printf("sa:\n");
  ft_print_stacks(temp1, temp2);
  printf("\n");

  pb(&temp1, &temp2);
  pb(&temp1, &temp2);
  pb(&temp1, &temp2);
  printf("pb:\n");
  ft_print_stacks(temp1, temp2);
  printf("\n");

  ra(&temp1, &temp2);
  rb(&temp1, &temp2);
  printf("ra:\n");
  ft_print_stacks(temp1, temp2);
  printf("\n");

  rra(&temp1, &temp2);
  rrb(&temp1, &temp2);
  printf("rra:\n");
  ft_print_stacks(temp1, temp2);
  printf("\n");

  sa(&temp1, &temp2);
  printf("sa:\n");
  ft_print_stacks(temp1, temp2);
  printf("\n");

  pa(&temp1, &temp2);
  pa(&temp1, &temp2);
  pa(&temp1, &temp2);
  printf("pa:\n");
  ft_print_stacks(temp1, temp2);
  printf("\n");

  //sort stacks

  return 0;
}