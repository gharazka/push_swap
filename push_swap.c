#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*num_list;
	int		*num_list_sorted;

	if (argc == 1)
		return (0);
	num_list = create_num_list(argc, argv);
	num_list_sorted = create_num_list(argc, argv);
	if (argc == 2)
		argc = get_num_count(argv[1]) + 1;
	if (!check_for_errors(num_list, num_list_sorted, argc))
		return (0);
	stack_a = init_linked_list(num_list, num_list_sorted, argc - 1);
	stack_b = NULL;
	bucket_sort(&stack_a, stack_b, argc - 1, 0);
	free(num_list);
	free(num_list_sorted);
	ft_lstclear(&stack_a);
	return (0);
}
