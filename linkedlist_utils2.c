#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

int	ft_lstfind_highest(t_list *lst, int type)
{
	int	highest;
	int	highest_index;
	int	i;

	highest = lst->rank;
	highest_index = 0;
	i = 0;
	while (lst)
	{
		if (lst->rank > highest)
		{
			highest = lst->rank;
			highest_index = i;
		}
		lst = lst->next;
		i++;
	}
	if (type == 1)
		return (highest_index);
	return (highest);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
