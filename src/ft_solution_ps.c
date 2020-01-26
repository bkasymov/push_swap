#include "../includes/push_swap.h"

/*
 ** At first we are finding max digit in stack_a
 ** Dividing solution to other 3 solutions;
 ** if digits 3, 5 or more;
 */

void        ft_solution_ps(t_vars *psv)
{
	int     max;

	max = ft_find_max(psv);
	if (psv->qa == 3)
		ft_3args_solution(psv, max);
	if (psv->qa == 5)
		ft_5args_solution(psv, max);
	if (psv->qa > 5)
		ft_general_solution(psv, max);
}

/*
 ** if digit of stack == max, our first maximum digit at first in stack and
 ** we are shifting up all elements by one. After it our max digit will be by end;
 **
 ** if max element on the second stage, we are shifting all elements by 1
 **
 ** And if first element more then last element, we are swaping this digits;
 */

void        ft_3args_solution(t_vars *psv, int max)
{
	if (psv->stack_a->data == max)
		ft_ra(psv, 1);
	if (psv->stack_a->next->data == max)
		ft_rra(psv, 1);
	if (psv->stack_a-> data > psv->stack_a->next->data)
		ft_sa(psv, 1);
}

void        ft_5args_solution(t_vars *psv, int max)
{
	return ;
}

void        ft_general_solution(t_vars *psv, int max)
{
	return ;
}

int     ft_find_max(t_vars *psv)
{
	int     res;
	t_stack *tmp;

	tmp = psv->stack_a;
	res = tmp->data;
	while (tmp)
	{
		if (tmp->data > res)
			res = tmp->data;
		tmp = tmp->next;
	}
	return (res);
}