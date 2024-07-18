#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				rank;
	struct s_list	*next;
}	t_list;

int			is_valid_number(const char *str);
int			*create_num_list_split(char *argv);
int			*create_num_list_argv(int argc, char *argv[]);
int			get_num_count(char *word);
int			*create_num_list(int argc, char *argv[]);
int			is_sorted(t_list *root, int size);
void		bucket_sort(t_list **stack_a, t_list *stack_b, int size, int pivot);
int			check_for_errors(int *num_list, int *num_list_sorted, int argc);
t_list		*init_linked_list(int *num_list, int *num_list_sorted,
				int num_size);
void		insertion_sort(int *num_list, int num_size);
void		push_biggest(t_list **stack_a, t_list *stack_b);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstfind_highest(t_list *lst, int type);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_lstdelone(t_list *lst);
t_list		*rotate(t_list *root, char *type);
t_list		*reverse_rotate(t_list *root, char *type);
t_list		*swap(t_list *root);
t_list		*push(t_list **stack_a, t_list *stack_b, char *type);
t_list		*sort_three(t_list *stack_a);
char		**ft_split(char const *s, char c);
long int	ft_atoi(const char *str);

#endif
