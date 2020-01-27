#include "../../includes/push_swap.h"

/*
 ** At first we are finding max digit in stack_a
 ** Dividing solution to other 3 solutions;
 ** if digits 3, 5 or more;
 */

void        ft_solver_ps(t_vars *psv)
{
	ft_find_bones(psv);
	if (psv->qa == 3)
		ft_3args_solution(psv);
	if (psv->qa == 5)
		ft_5args_solution(psv);
	if (psv->qa > 5)
		ft_general_solution(psv);
}

/*
 ** if digit of stack == max, our first maximum digit at first in stack and
 ** we are shifting up all elements by one. After it our max digit will be by end;
 **
 ** if max element on the second stage, we are shifting all elements by 1
 **
 ** And if first element more then last element, we are swaping this digits;
 */

void        ft_3args_solution(t_vars *psv)
{
	if (psv->stack_a->data == psv->mass[2])
		ft_ra(psv, 1);
	if (psv->stack_a->next->data == psv->mass[2])
		ft_rra(psv, 1);
	if (psv->stack_a-> data > psv->stack_a->next->data)
		ft_sa(psv, 1);
}

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
	if (psv->stack_a->data == psv->mass[0])
		ft_ra(psv, 1);
	else
	{
		ft_sa(psv, 1);
		ft_ra(psv, 1);
	}
}

void        ft_general_solution(t_vars *psv)
{
	return ;
}

/*
 ** I don't know but my psv->qa (quantity of stack_a)
 ** changing in cycle when i'm searcing digit with max value
 ** in stack_a. Therefore I decide to save first value in variable
 ** save;
 */

void     ft_find_bones(t_vars *psv)
{
	t_stack *tmp;
	int     i;
	int     save;

	tmp = psv->stack_a;
	while (tmp)
	{
		if (tmp->data < psv->mass[0])
			psv->mass[0] = tmp->data;
		tmp = tmp->next;
	}
	i = psv->qa;
	i /= 2;
	tmp = psv->stack_a;
	while (i) {
		tmp = tmp->next;
		i--;
	}
	save = psv->qa;
	psv->mass[1] = tmp->data;
	tmp = psv->stack_a;
	psv->mass[2] = tmp->data;
	while (tmp) //Why psv->qa changing here? WHY? We are not using this variable here.
	{
		if (tmp->data > psv->mass[2])
			psv->mass[2] = tmp->data;
		tmp = tmp->next;
	}
	psv->qa = save;
}
