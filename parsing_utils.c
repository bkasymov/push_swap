#include "./includes/push_swap.h"

/*
** It's first checking of numbers. If something except numbers - error;
** && (str[i + 1] >= '0' && str[i + 1] <= '9'))))
*/

int		ft_first_check(char *str)
{
	int		i;

	i = 0;
	while(str[i] != '\0')
	{
		if ((ft_isdigit(str[i])) == 1 || (str[i] == ' ') || (str[i] == '-'))
			i++;
		else
			return(1);
	}
	return(0);
}

int     ft_parting_array(int *array, int start, int end)
{
	int i;
	int temp;
	int j;
	int pivot;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot) {
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}

void    ft_quick_sort_ps(int *array, int start, int end)
{
	int     q;

	if (start < end)
	{
		q = ft_parting_array(array, start, end);
		ft_quick_sort_ps(array, start, q - 1);
		ft_quick_sort_ps(array, q + 1, end);
	}
}

/*
 ** argc - 1 because it's name of programms
 */

int		*ft_intcpy(int *dst, const int *src, int count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int     ft_check_duplicates(t_stacks *vars, int argc)
{
	int     i;
	int     j;
	int     *dupl;

	i = 0;
	j = 0;
	//argc -= 2;
	dupl = (int *)malloc(sizeof(int) * (argc - 1));
	printf("%lu", sizeof(dupl));
	dupl = ft_intcpy(dupl, vars->a, argc - 1);
	ft_quick_sort_ps(dupl, 0, argc - 2);
	while (argc > i - 2)
	{
		if (dupl[i] == dupl[i + 1])
			error_print(vars);
		i++;
	}
	free(dupl);
	return (0);
}

/*
 ** performed copy of ft_atoi
 ** but specification of it that:
 ** 1. miss all 0 symbols before number;
 ** 2. if strings number more than int - calling error_print
 */

int					ft_atoips(t_stacks *vars, const char *str)
{
	size_t					i;
	int						sym;
	int	                    res;

	i = 0;
	sym = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	       || str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		sym = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == 0)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
		if (i > 10 || (res * sym) < INT_MIN || (res * sym) > INT_MAX)
			error_print(vars);
	}
	return (res * sym);
}

/*
** function which print Error message;
** free stacks variables;
** write "Error";
*/

void	error_print(t_stacks *vars)
{
	free(vars->a);
	free(vars->b);
	write(2, "Error\n", 7);
	exit(1);
}