# include "rules.h"

/*
 * push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
 * And to upper all digits to up;
 */

void        ft_pb(t_vars *psv)
{
	int     i;

	i = 0;
	psv->b[0] = psv->a[0];
	psv->qa -= 1;
	while (psv->qa > i)
	{
		psv->a[i] = psv->a[i + 1];
		i++;
	}

}
