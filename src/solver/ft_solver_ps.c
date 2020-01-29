#include "../../includes/push_swap.h"

/*
 ** At first we are finding max digit in stack_a
 ** Dividing solution to other 3 solutions;
 ** if digits 3, 5 or more;
 */

void        ft_solver_ps(t_vars *psv)
{
	ft_find_bones(psv);
	if (psv->qa == 2) {
		if (psv->stack_a->data > psv->stack_a->next->data)
			ft_sa(psv, 1);
		return ;
	}
	if (psv->qa <= 3)
		ft_3args_solution(psv);
	if (psv->qa <= 5)
		ft_5args_solution(psv);
	if (psv->qa > 5)
		ft_general_solution(psv);
}

void        ft_3args_solution(t_vars *psv)
{
	if (psv->stack_a->data == psv->mass[2])
		ft_ra(psv, 1);
	if (psv->stack_a->next->data == psv->mass[2])
		ft_rra(psv, 1);
	if (psv->stack_a-> data > psv->stack_a->next->data)
		ft_sa(psv, 1);
}

/*
 ** a) max and min value putting to stack_b with cycle less 2;
 ** b) sending to sort of 3 element to function ft_3args_solution;
 ** c) after it returning back elements from stack_b to stack_a;
 ** d) if first element is max, using ft_ra than to put it to last list
 ** e) if first element is min, using ft_sa than to swap min and max values and ft_ra than to put max to last list;
 */

void        ft_5args_solution(t_vars *psv)
{
	while (psv->qb < 2)
	{
		if (psv->stack_a->data == psv->mass[2] || psv->stack_a->data == psv->mass[0])
			ft_pb(psv, 1);
		else
			ft_ra(psv, 1);
	}
	ft_3args_solution(psv);
	ft_pa(psv, 1);
	ft_pa(psv, 1);
	if (psv->stack_a->data == psv->mass[2])
		ft_ra(psv, 1);
	else
	{
		ft_sa(psv, 1);
		ft_ra(psv, 1);
	}
}

