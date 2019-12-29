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

#include "push_swap.h"

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
	 if (ft_check_duplicates(vars, res) == 1)
	 	error_print(vars);
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
			if(!(vars->a[i - 1] = ft_atoips(vars ,argv[i])))
				return(1);
			++i;
			printf("%d\n", vars->a[j]);
			j++;
	}
	ft_check_duplicates(vars, argc);
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
