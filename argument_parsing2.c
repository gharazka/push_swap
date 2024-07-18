#include "push_swap.h"

static void	free_split(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	word_count(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		i++;
	return (i);
}

int	get_num_count(char *word)
{
	char	**words;
	int		i;

	if (!word[0])
		return (0);
	words = ft_split(word, ' ');
	i = word_count(words);
	free_split(words);
	return (i);
}

int	*create_num_list_split(char *argv)
{
	int		*num_list;
	char	**words;
	int		i;

	i = 0;
	words = ft_split(argv, ' ');
	num_list = (int *)malloc(sizeof(int) * word_count(words));
	while (words[i])
	{
		if (!is_valid_number(words[i]))
		{
			free(num_list);
			free_split(words);
			return (NULL);
		}
		num_list[i] = ft_atoi(words[i]);
		i++;
	}
	free_split(words);
	return (num_list);
}

int	*create_num_list_argv(int argc, char *argv[])
{
	int		*num_list;
	int		i;

	i = 0;
	num_list = (int *)malloc(sizeof(int) * (argc));
	while (i < argc - 1)
	{
		if (!is_valid_number(argv[i + 1]))
		{
			free(num_list);
			return (NULL);
		}
		num_list[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (num_list);
}
