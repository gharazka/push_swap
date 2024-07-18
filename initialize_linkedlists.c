#include "push_swap.h"

static void	assign_ranks(t_list *root, int *num_list_sorted)
{
	int		i;

	while (root)
	{
		i = 0;
		while (num_list_sorted[i] != root->content)
			i++;
		root->rank = i + 1;
		root = root->next;
	}
}

static t_list	*make_n_nodes(t_list *root, int *num_list, int num_size)
{
	int		i;
	t_list	*new;
	t_list	**swap;

	if (num_size == 0)
		return (NULL);
	root = ft_lstnew(num_list[0]);
	swap = &root;
	i = 1;
	while (i < num_size)
	{
		new = ft_lstnew(num_list[i]);
		ft_lstadd_back(swap, new);
		i++;
	}
	return (root);
}

t_list	*init_linked_list(int *num_list, int *num_list_sorted, int num_size)
{
	t_list	*stack_a;

	insertion_sort(num_list_sorted, num_size);
	stack_a = NULL;
	stack_a = make_n_nodes(stack_a, num_list, num_size);
	assign_ranks(stack_a, num_list_sorted);
	return (stack_a);
}
