/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:24:57 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/12 12:27:13 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			ft_general_parser(int argc, char **argv, t_vars *psv)
{
	if (argc == 2)
	{
		if (ft_args_in_1_string(argv[1], psv) == 1)
		{
			error_print(psv, 0);
			return (1);
		}
	}
	else if (argc == 1)
		return (1);
	else
	{
		if ((ft_args_in_other_strings(argv, argc, psv) == 1))
			error_print(psv, 0);
	}
	return (0);
}

void		ft_init_lists(t_vars *psv, int mem)
{
	psv->stack_a = ft_malloc_list(psv, mem);
	psv->stack_b = NULL;
	psv->qb = 0;
}

/*
** Creating 2 links of lists format;
** list - than to create and move this list forward
** first - keep address of first list;
** allocating memory for list and keeping it's address
** in first variable;
** Mem keeping count of values for record.
** In cycle recording all values to lists;
*/

t_stack		*ft_malloc_list(t_vars *psv, int mem)
{
	int		i;
	t_stack	*list;
	t_stack	*first;

	i = 0;
	if (!(list = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	first = list;
	while (i < mem)
	{
		if (i < mem - 1)
		{
			if (!(list->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(1);
		}
		list->data = psv->arr[i];
		if (i == (mem - 1))
			list->next = NULL;
		else
			list = list->next;
		i++;
	}
	return (first);
}

/*
** At first checking string if it have something except digits;
** splitting to array all elements of string between spaces;
** Finding count of values in string through num_word  function;
** allocating memory for stack variables;
** converting all separate digits to integer and filling stack a;
*/

int			ft_args_in_1_string(char *str, t_vars *psv)
{
	int		res;
	int		i;
	char	**split;

	psv->arr = NULL;
	if ((ft_check_sym(str)) == 1)
		return (1);
	split = ft_strsplit(str, ' ');
	res = num_word(str, ' ');
	ft_init_array(psv, res + 1, 0);
	i = 0;
	while (res > i)
	{
		psv->arr[i] = ft_atoips(psv, split[i]);
		i++;
	}
	psv->qa = i;
	free(split);
	ft_init_lists(psv, res);
	return (0);
}

/*
** checking all arguments than be just digits;
** allocating memory for stacks;
** filling with arguments from argv to stack A;
*/

int			ft_args_in_other_strings(char **argv, int argc, t_vars *psv)
{
	int		i;

	i = 1;
	psv->arr = NULL;
	while (argc > i)
		if ((ft_check_sym(argv[i++])) == 1)
			return (1);
	if (ft_init_array(psv, argc, 1))
	  return (1);
	i = 1;
        while (argc > i)
	{
		psv->arr[i - 1] = ft_atoips(psv, argv[i]);
		i++;
	}
	psv->qa = i - 1;
	ft_init_lists(psv, psv->qa);
	return (0);
}
