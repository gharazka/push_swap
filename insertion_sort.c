#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	insertion_sort(int *num_list, int num_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (num_size))
	{
		j = 1;
		while (i + j < num_size)
		{
			if (num_list[i] > num_list[i + j])
				ft_swap(&num_list[i], &num_list[i + j]);
			j++;
		}
		i++;
	}
}

static int	look_forward(t_list *lst, int h_index, int h_num)
{
	int	i;
	int	lst_size;

	lst_size = ft_lstsize(lst);
	i = 0;
	if (lst->rank == h_num - 1)
		return (0);
	while (lst)
	{
		if (lst->rank == h_num - 1 && h_index >= lst_size / 2 && i > h_index)
			return (i);
		if (lst->rank == h_num - 1 && h_index < lst_size / 2 && i < h_index)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

static t_list	*on_the_way(t_list **stack_a,
				t_list *stack_b, int h_index, int h_num)
{
	int	new_index;

	new_index = look_forward(stack_b, h_index, h_num);
	if (new_index != -1)
		stack_b = on_the_way(stack_a, stack_b, new_index, h_num - 1);
	else
		return (stack_b);
	if (h_index >= ft_lstsize(stack_b) / 2)
	{
		while (stack_b->rank != (h_num - 1))
			stack_b = reverse_rotate(stack_b, "rrb");
	}
	else
	{
		while (stack_b->rank != (h_num - 1))
			stack_b = rotate(stack_b, "rb");
	}
	*stack_a = push(&stack_b, *stack_a, "pa");
	if ((*stack_a)->next)
		*stack_a = rotate(*stack_a, "ra");
	return (stack_b);
}

void	push_biggest(t_list **stack_a, t_list *stack_b)
{
	int	highest_index;
	int	highest;
	int	lst_size;

	*stack_a = sort_three(*stack_a);
	while (stack_b)
	{
		highest_index = ft_lstfind_highest(stack_b, 1);
		highest = ft_lstfind_highest(stack_b, 0);
		lst_size = ft_lstsize(stack_b);
		stack_b = on_the_way(stack_a, stack_b, highest_index, highest);
		highest_index = ft_lstfind_highest(stack_b, 1);
		if (highest_index == 0)
		{
			*stack_a = push(&stack_b, *stack_a, "pa");
			while (!is_sorted(*stack_a, ft_lstsize(*stack_a)))
				*stack_a = reverse_rotate(*stack_a, "rra");
		}
		else if (highest_index < (lst_size / 2))
			stack_b = rotate(stack_b, "rb");
		else
			stack_b = reverse_rotate(stack_b, "rrb");
	}
}
