#include "push_swap.h"

static int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	sign = ft_issign(str[0]);
	if (ft_isdigit(str[0]))
		result = str[0] - 48;
	else
		result = 0;
	i = 1;
	while (str[i])
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (sign)
		result *= sign;
	return (result);
}

int	is_valid_number(const char *str)
{
	int	i;

	if ((!ft_isdigit(str[0]) && !ft_issign(str[0])) || !str[0])
		return (0);
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	if (ft_issign(str[0]) && !str[1])
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*create_num_list(int argc, char *argv[])
{
	if (argc == 2)
		return (create_num_list_split(argv[1]));
	return (create_num_list_argv(argc, argv));
}
