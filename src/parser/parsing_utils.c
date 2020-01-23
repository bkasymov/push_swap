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
#include "../../libft/ft_printf/printf.h"

void    ft_init_lists(t_vars *psv, int  mem)
{
  psv->stack_a = ft_malloc_list(psv, mem);
  psv->stack_b = NULL;
}

/*
 * Creating 2 links of lists format;
 * list - than to create and move this list forward
 * first - keep address of first list;
 * allocating memory for list and keeping it's address
 * in first variable;
 * Mem keeping count of values for record.
 * In cycle recording all values to lists;
 */

t_stack  *ft_malloc_list(t_vars *psv, int mem)
{
  int       i;
  t_stack   *list;
  t_stack   *first;

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
    list->data = psv->a[i];
    if (i == (mem - 1))
        list->next = NULL; //
    else
      list = list->next;
    i++;
  }
  return (first);
}

void    ft_free_list(t_vars *psv)
{
    int     i;
    t_stack *tmp;

    i = 0;
    while (i < psv->qa)
    {
        tmp = psv->stack_a;
        psv->stack_a = psv->stack_a->next;
        free(tmp);
        i++;
    }
    i = 0;
    while (i < psv->qb)
    {
        tmp = psv->stack_b;
        psv->stack_b = psv->stack_b->next;
        free(tmp);
        i++;
    }
}
/*
** function which print Error message;
** free stacks variables;
** write "Error";
*/

void	error_print(t_vars *psv)
{
	free(psv->a);
	free(psv->b);
	free(psv->stack_a);
	//free(psv->stack_b);
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
	char	        **split;
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
	printf("\nHas parsed next numbers\n");
	res--;
	while (res >= i)
	{
		psv->a[i] = ft_atoips(psv, split[i]);
		i++;
	}
	psv->qa = i;
	ft_init_lists(psv, res + 1);
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
	i = 1;
	printf("\nHas parsed next numbers\n");
	while (argc > i)
	{
	  if(!(psv->a[i - 1] = ft_atoips(psv ,argv[i]))) //не записывает пятёрку.
	    return(1);
	  i++;
	}
	psv->qa = i - 1;
    ft_init_lists(psv, psv->qa);
	return (0);
}