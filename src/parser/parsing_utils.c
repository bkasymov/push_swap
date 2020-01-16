/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 23:17:18 by dpenney           #+#    #+#             */
/*   Updated: 2020/01/08 23:17:20 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** function which print Error message;
** free stacks variables;
** write "Error";
*/

void	error_print(t_vars *psv)
{
	free(psv->a);
	free(psv->b);
	write(2, "Error\n", 7);
	exit(1);
}

/*
** At first checking string if it have something except digits;
** splitting to array all elements of string between spaces;
** Finding count of values in string through num_word  function;
** allocating memory for stack variables;
** converting all separate digits to integer and filling stack a;
*/

int		ft_args_in_1_string(char *str, t_vars *psv)
{
	int		res;
	int		i;
	char	**split;
	int		j;

	j = 0;
	res = 0;
	i = 0;
	if ((res = ft_check_sym(str)) == 1)
		return(1);
	split = ft_strsplit(str, ' ');
	res = num_word(str, ' ');
	if (!(psv->a = ft_memalloc(res)) && !(psv->b = ft_memalloc(res)))
		return(1);
	ft_printf("\nHas parsed next numbers\n");
	res--;
	while (res >= 0)
	{
		psv->a[i] = ft_atoips(psv, split[res]);
		res--;
		i++;
	}
	psv->qa = i;
    while (i > j)
    {
        printf("%d\n", psv->a[j]);
        j++;
    }
	j = 0;
	return (0);

}


/*
** checking all arguments than be just digits;
** allocating memory for stacks;
** filling with arguments from argv to stack A;
**
*/

int		ft_args_in_other_strings(char **argv, int argc, t_vars *psv)
{
	int		i;
	int		res;
	int		j;

	j = 0;
	res = 0;
	i = 1;
	while(argc > i)
		if ((ft_check_sym(argv[i++])) == 1)
			return(1);
	if (!(psv->a = (int *)malloc(sizeof(int) * (argc - 1))))
		exit(1);
	if (!(psv->b = (int *)malloc(sizeof(int) * (argc - 1))))
		exit(1);
	i = 0;
	ft_printf("\nHas parsed next numbers\n");
	while (argc > 1)
	{
		if(!(psv->a[i] = ft_atoips(psv ,argv[argc - 1]))) //не записывает пятёрку.
			return(1);
		argc--;
		i++;
	}
	psv->qa = i;
	while (i > j)
    {
	    printf("%d\n", psv->a[j]);
	    j++;
    }
	return (0);
}
