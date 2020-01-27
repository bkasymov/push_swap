#include "../../includes/push_swap.h"

/*
** This function will check the order of the digits.
** if all digits in right order, we should to return nothing.
** in cycle launching my array, where all digits.
** if even next digit bigger than current digit, we are counting
** it like iteration. After all we are comparing our iteretions
** if both iterations is equal it's mean that order is right.
 */

int             ft_is_it_sorted(t_vars *psv)
{
	int     i;
	int     max;
	int     *tmp;
	int     j;

	j = 0;
	tmp = psv->arr;
	i = 0;
	while (psv->arr[i])
	{
		if (psv->arr[i] > max)
		{
			max = psv->arr[i];
			j++;
		}
		i++;
	}
	if (j == i) {
		free(psv->stack_a);
		free(psv->arr);
		return (1);
	}
	return (0);
}