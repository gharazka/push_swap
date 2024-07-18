#include "push_swap.h"

static void	process_errors(int *num_list, int *num_list_sorted)
{
	write(2, "Error\n", 6);
	free(num_list);
	free(num_list_sorted);
}

static int	check_for_duplicates(int *num_list, int num_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_size - 1)
	{
		j = i + 1;
		while (j < num_size - 1)
		{
			if (num_list[i] == num_list[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_for_errors(int *num_list, int *num_list_sorted, int argc)
{
	if (!num_list || !check_for_duplicates(num_list, argc) || argc == 1)
	{
		process_errors(num_list, num_list_sorted);
		return (0);
	}
	return (1);
}
