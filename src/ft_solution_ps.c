#include "../includes/push_swap.h"

/*
 ** At first we are finding max digit in stack_a
 ** Dividing solution to other 3 solutions;
 ** if digits 3, 5 or more;
 */

void        ft_solution_ps(t_vars *psv)
{
	ft_find_max(psv);
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

void     ft_find_max(t_vars *psv)
{
	t_stack *tmp_max;
	t_stack *tmp_min;
	t_stack *tmp_mid;
	int     i;

	i = 0;
	tmp_max = psv->stack_a;
	tmp_min = psv->stack_a;
	tmp_mid = psv->stack_a;
	while (tmp_min)
	{
		if (tmp_min->data < psv->mass[0])
			psv->mass[0] = tmp_min->data;
		tmp_min = tmp_min->next;
	}
	i = psv->qa;
	i /= 2;
	while (i) {
		tmp_mid = tmp_mid->next;
		i--;
	}
	psv->mass[1] = tmp_mid->data;
	psv->mass[2] = tmp_max->data;
	while (tmp_max) //Why psv->qa changing here? WHY? We are not using this variable here.
	{
		if (tmp_max->data > psv->mass[2])
			psv->mass[2] = tmp_max->data;
		tmp_max = tmp_max->next;
	}
}