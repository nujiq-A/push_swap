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

bool ft_check_args(int ac, char **av)
{
  int i;
  int j;

  i = 1;
  while (i < ac)
  {
    if (ft_strchr(av[i], ' ') && !ft_isdigit(av[i][0]) && av[i][0] != '-')
    {
      printf("Error\n");
      return false;
    }
    j = 0;
    while (av[i][j] != '\0')
    {
      if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
      {
        printf("Error\n");
        return false;
      }
      if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
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

void  ft_free_split(char **temp)
{
  int i;

  i = 0;
  while (temp[i] != NULL)
  {
    free(temp[i]);
    i++;
  }
  free(temp);
}

void  handle_string(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
  int i;
  int j;
  char **temp;

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

int main(int ac, char **av)
{
	t_list *stack_a;
  t_list *stack_b;
  int i;
  t_list *temp;

  if (!ft_check_args(ac, av))
    return 0;
	stack_a = ft_lstnew(NULL);
  stack_b = ft_lstnew(NULL);
  if (stack_a == NULL || stack_b == NULL)
    return 0;
  handle_string(ac, av, &stack_a, &stack_b);
  // i = 1;
	// while (i < ac)
	// {
	// 	temp = ft_newval(ft_atoi(av[i]));
	// 	if (temp == NULL)
	// 		return (0);
	// 	ft_lstadd_back(&stack_a, temp);
	// 	i++;
	// }
  t_list *temp1 = stack_a->next;
  t_list *temp2 = stack_b->next;
  //sort stacks

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