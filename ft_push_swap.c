/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:40:39 by dpenney           #+#    #+#             */
/*   Updated: 2019/12/23 15:40:42 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "push_swap.h"
#include "limits.h"

/*
** it's structure of data which keeping all variables;
*/

typedef		struct stacks
{
	int			*a;
	int			*b;
	int			i;
	int			j;
	int			res;
}				t_stacks;

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
** It's first checking of numbers. If something except numbers - error; 
*///&& (str[i + 1] >= '0' && str[i + 1] <= '9'))))

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
** At first checking string if it have something except digits;
** splitting to array all elements of string between spaces;
** Finding count of values in string through num_word  function;
** allocating memory for stack variables;
** converting all separate digits to integer and filling stack a;
*/

int		ft_args_in_1_string(char *str, t_stacks *vars)
{
	int		res;
	int		i;
	char	**split;
	int		j;

	j = 0;
	res = 0;
	i = 0;
	if ((res = ft_first_check(str)) == 1)
		return(1);
	split = ft_strsplit(str, ' ');
	res = num_word(str, ' ');
	if (!(vars->a = ft_memalloc(res)) && !(vars->b = ft_memalloc(res)))
		return(1);
	while (res > i)
	{
		vars->a[i] = ft_atoips(vars, split[i]);
		i++;
		printf("%d\n", vars->a[j]);
		j++;
	}
	return (0);
}


/*
** checking all arguments than be just digits;
** allocating memory for stacks;
** filling with arguments from argv to stack A;
** 
*/

int		ft_args_in_other_strings(char **argv, int argc, t_stacks *vars)
{
	int		i;
	int		res;
	int		j;

	j = 0;
	res = 0;
	i = 1;
	while(argc > i)
			if ((ft_first_check(argv[i++])) == 1)
				return(1);
	if (!(vars->a = ft_memalloc(argc)) && !(vars->b = ft_memalloc(argc)))
		return(1); 
	i = 1;
	while (argc > i)
	{
			if (!(vars->a[i - 1] = ft_atoi(argv[i])))
				return(1);
			++i;
			printf("%d\n", vars->a[j]);
			j++;
	}
	return (0);
}

/*
 ** Program getting argument and checking.
 ** if 2 argument - dividing string to separate array strings,
 ** check all string that it's all numbers and after it converting to
 ** integer type and recording to stack a;
 ** if argument just 1 or less - finishing work;
 ** else every argument getting separate - checking that all arguments are digits and
 ** recording to array

** code which split our string to separate string with numbers
** after it check array and confident that every symbols are digits,
** without any other.
** after it through ft_atoi will convert to numbers and record to stack.
** and free result of ft_strsplit
*/

int		main(int argc, char **argv)
{
	t_stacks	vars;

	if (argc == 2)
	{
		if (ft_args_in_1_string(argv[1], &vars) == 1)
		{
			return(1);
		}
	}
	else if (argc == 1)
		return(1);
	else
		if ((ft_args_in_other_strings(argv, argc, &vars) == 1))
			error_print(&vars);
	return(0);
}
