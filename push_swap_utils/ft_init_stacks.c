#include "../push_swap.h"

void  ft_free_stack(t_list *stack)
{
  t_list *temp;

  while (stack != NULL)
  {
    temp = stack;
    stack = stack->next;
    free(temp->content);
    free(temp);
  }
}

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
  // printf("Stack B: ");
  // while (temp != NULL)
  // {
  //   printf("%d ", *(int *)temp->content);
  //   temp = temp->next;
  // }
  // printf("\n");
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

bool ft_check_args(char **av)
{
  int i;
  int j;

  i = 1;
  while (av[i] != NULL)
  {
    j = 0;
    while (av[i][j] != '\0')
    {
      if (av[i][j] == '-' && j == 0)
        j++;
      if (av[i][j] < '0' || av[i][j] > '9')
      {
        printf("Error\n");
        return false;
      }
      j++;
    }
    i++;
  }
  return true;
}

bool ft_sorted(t_list **stack_a, t_list **stack_b)
{
  t_list *temp;
  int prev;
  int curr;

  temp = *stack_a;
  if (temp == NULL)
    return true;
  prev = *(int *)temp->content;
  temp = temp->next;
  while (temp != NULL)
  {
    curr = *(int *)temp->content;
    if (prev > curr)
      return false;
    prev = curr;
    temp = temp->next;
  }
  temp = *stack_b;
  if (temp == NULL)
    return true;
  prev = *(int *)temp->content;
  temp = temp->next;
  while (temp != NULL)
  {
    curr = *(int *)temp->content;
    if (prev < curr)
      return false;
    prev = curr;
    temp = temp->next;
  }
  return true;
}

int main(int ac, char **av)
{
	t_list *stack_a;
  t_list *stack_b;
  int i;
  t_list *temp;

	if (ac < 2)
		return 0;
  if (!ft_check_args(av))
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
  //sort stacks
  // ft_print_stacks(temp1, temp2);

  // push_largest(&temp1, &temp2);
  // ft_print_stacks(temp1, temp2);
  // int j = 0;
  // while(!ft_sorted(&temp1, &temp2))
  // {
  //   push_largest(&temp1, &temp2);
  //   ft_print_stacks(temp1, temp2);
  //   j++;
  //   if (j > 500)
  //     break;
  // }

  int j = 0;
  while(!ft_sorted(&temp1, &temp2))
  {
    push_smallest(&temp1, &temp2);
    // ft_print_stacks(temp1, temp2);
    j++;
    if (j > 500)
      break;
  }

  while(temp2 != NULL)
  {
    pa(&temp1, &temp2);
    // ft_print_stacks(temp1, temp2);
  }

  ft_free_stack(stack_a);
  ft_free_stack(stack_b);
  return 0;
}