#include "push_swap.h"

t_list	*swap(t_list *root)
{
	t_list	*swap;

	swap = root->next;
	root->next = root->next->next;
	swap->next = root;
	write(1, "sa\n", 3);
	return (swap);
}

t_list	*rotate(t_list *root, char *type)
{
	t_list	*new_root;

	if ((!root) || (!root->next))
		return (root);
	new_root = root->next;
	ft_lstadd_back(&new_root, root);
	root->next = NULL;
	if (type[1] == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	return (new_root);
}

t_list	*reverse_rotate(t_list *root, char *type)
{
	t_list	*last;
	t_list	*sec_last;

	if ((!root) || (!root->next))
		return (root);
	last = root->next;
	sec_last = root;
	while (last->next)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = root;
	if (type[2] == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	return (last);
}

t_list	*push(t_list **stack_a, t_list *stack_b, char *type)
{
	t_list	*swap;

	swap = (*stack_a)->next;
	if (!stack_b)
	{
		stack_b = *stack_a;
		stack_b->next = NULL;
	}
	else
	{
		(*stack_a)->next = stack_b;
		stack_b = *stack_a;
	}
	*stack_a = swap;
	if (type[1] == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return (stack_b);
}

t_list	*sort_three(t_list *stack_a)
{
	int	highest_index;

	highest_index = ft_lstfind_highest(stack_a, 1);
	if (is_sorted(stack_a, 3))
		return (stack_a);
	if (highest_index == 2)
		stack_a = swap(stack_a);
	else if (highest_index == 0)
		stack_a = rotate(stack_a, "ra");
	else if (highest_index == 1)
		stack_a = reverse_rotate(stack_a, "rra");
	if (!is_sorted(stack_a, 3))
		stack_a = swap(stack_a);
	return (stack_a);
}
