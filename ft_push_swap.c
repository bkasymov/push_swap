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

int             ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

/*
** function which print Error message;
*/

void	error_print(void)
{
		ft_printf("Error\n");
}

/*
** It's first checking of numbers. If something except numbers - error; 
*/

int		ft_check_string(char *str)
{
	int		i;

	i = 0;
	while(*str)
	{
		if (ft_isdigit(*str) == 1 || *str == ' ' || *str == '-')
			*str++;
		else
		{
			error_print();
			return(1);
		}
	}
	return(0);
}

/*
** At first checking string if it have something except digits;
** splitting to array all elements of string between spaces;
** Finding count of values in string through num_word  function;
** allocating memmory for stack variables;
** converting all separate digits to integer and filling stack a;
*/

int		ft_args_in_1_string(char *str, t_stacks *vars)
{
	int		res;
	int		i;
	char	**split;

	res = 0;
	i = 0;
	if ((res = ft_check_string(str)) == 1)
		return(1);
	split = ft_strsplit(str, ' ');
	res = num_word(str, ' ');
	vars->a = (int *)malloc(sizeof(int) * res);
	vars->b = (int *)malloc(sizeof(int) * res);
	while (res > i)
	{
		vars->a[i] = ft_atoi(split[i]);
		i++;
	}
	return (0);
}


/*
** checking all arguments than be just digits;
** allocating memory for stacks;
** filling with arguments from argv to stack A;
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
		if ((res = ft_check_string(argv[i++])) == 1)
			return(1);
	vars->a = (int *)malloc(sizeof(int) * argc);
	vars->b = (int *)malloc(sizeof(int) * argc);
	while (argc > 0)
	{
		vars->a[res] = ft_atoi(argv[res]);
		res++;
		argc--;
		printf("%d", vars->a[res]);
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
		return(ft_args_in_1_string(argv[1], &vars));
	else if (argc == 1)
		return(0);
	else
		return(ft_args_in_other_strings(argv, argc, &vars));
	return(0);
}
