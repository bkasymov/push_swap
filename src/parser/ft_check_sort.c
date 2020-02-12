#include "../../includes/push_swap.h"

/*
** This function will check the order of the digits.
** if all digits in right order, we should to return nothing.
** in cycle launching my array, where all digits.
** if even next digit bigger than current digit, we are counting
** it like iteration. After all we are comparing our iteretions
** if both iterations is equal it's mean that order is right.
 */

int             ft_check_sort(t_vars *psv)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
	while (i < psv->qa - 1)
    {
	    if (psv->arr[i] < psv->arr[i + 1])
	        j++;
	    i++;
    }
	if (i == j) {
	    ft_free_list(psv, 1);
        return (1);
    }
	return (0);
}