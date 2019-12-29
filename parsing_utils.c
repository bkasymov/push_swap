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

/*
 ** argc - 1 because it's name of programm
 */

int     ft_check_duplicates(t_stacks *vars, int argc)
{
	int     i;
	int     j;
	int     z;

	i = 0;
	j = 0;
	z = 0;
	argc -= 1;
	while (argc > i)
	{
		while (argc > j)
		{
			if (vars->a[i] == vars->a[j])
				z += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (z == 2)
		error_print(vars);
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
	int	res;

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