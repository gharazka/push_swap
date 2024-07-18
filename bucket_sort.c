#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (nb / i > i)
	{
		if (nb / i == i)
			return (i);
		i++;
	}
	return (i);
}

static int	get_buckets_amount(int num_size)
{
	int		sqrt_num_size;

	sqrt_num_size = ft_sqrt(num_size);
	return (sqrt_num_size / 2.73 + 1);
}

int	is_sorted(t_list *root, int size)
{
	if (!root)
		return (0);
	if (ft_lstsize(root) != size)
		return (0);
	while (root->next)
	{
		if (root->rank > root->next->rank)
			return (0);
		root = root->next;
	}
	return (1);
}

void	bucket_sort(t_list **stack_a, t_list *stack_b, int size, int pivot)
{
	int	i;
	int	bucket_amount;
	int	sec_pivot;

	if (ft_lstsize(*stack_a) == 3)
		push_biggest(stack_a, stack_b);
	i = 0;
	bucket_amount = get_buckets_amount(size);
	pivot += size / bucket_amount;
	sec_pivot = pivot - (size / (bucket_amount * 2));
	while (!is_sorted(*stack_a, size))
	{
		if ((*stack_a)->rank <= pivot && (*stack_a)->rank < size - 2)
		{
			stack_b = push(stack_a, stack_b, "pb");
			i++;
		}
		else
			*stack_a = rotate(*stack_a, "ra");
		if (stack_b && stack_b->next && stack_b->next->rank <= sec_pivot
			&& stack_b->rank >= sec_pivot)
			stack_b = rotate(stack_b, "rb");
		if (i >= (size / bucket_amount) || ft_lstsize(*stack_a) == 3)
			bucket_sort(stack_a, stack_b, size, pivot);
	}
}
