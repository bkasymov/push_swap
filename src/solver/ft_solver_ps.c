#include "../../includes/push_swap.h"

/*
 ** At first we are finding max digit in stack_a
 ** Dividing solution to other 3 solutions;
 ** if digits 3, 5 or more;
 */

void        ft_solver_ps(t_vars *psv) {
	ft_find_bones(psv);
	if (psv->qa == 2) {
		if (psv->stack_a->data > psv->stack_a->next->data)
			ft_sa(psv, 1);
	}
	if (psv->qa == 3)
		ft_3args_solution(psv);
	if (psv->qa == 5)
		ft_5args_solution(psv);
	if (psv->qa > 5)
	{
		ft_calc_step(psv);
		ft_general_solution(psv);
	}
}

void        ft_calc_step(t_vars *psv)
{
	int     i;
	int     mid;
	t_stack  *list;
	t_stack  *list2;

	i = 1;
	mid = psv->qa / 2;
	list = psv->stack_a;
	while (mid)
	{
		list->step = 0 + i;
		list = list->next;
		mid--;
		i++;
	}
	i = psv->qa;
	while (i != mid)
	{
		list
	}
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

void        ft_general_solution(t_vars *psv)
{
	t_stack *a;
	t_stack *b;

	a = psv->stack_a;
	b = psv->stack_b;
	while (a)
	{
		if (psv->mass[1] >= a->data && a->data != psv->mass[0] && a->data != psv->mass[2])
		{
			ft_pb(psv, 1);
		}
		else if (a->data > psv->mass[1] && a->data != psv->mass[0] && a->data != psv->mass[2])
		{
			ft_pb(psv, 1);
			ft_rb(psv, 1);
		}
		a = a->next;
	}
}

void     ft_quick_sort(int *array, int start, int end)
{
	int     i;

	if (start < end)
	{
		i = ft_parting(array, start, end);
		ft_quick_sort(array, start, i - 1);
		ft_quick_sort(array, i + 1, end);
	}
}

int     ft_parting(int *array, int start, int end)
{

	int     i;
	int     j;
	int     tmp;
	int     pivot;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = tmp;
	return (i + 1);
}

/*
 ** I don't know but my psv->qa (quantity of stack_a)
 ** changing in cycle when i'm searcing digit with max value
 ** in stack_a. Therefore I decide to save first value in variable
 ** save;
 ** psv->mass[0] saving minimum, [1] saving medium, [2] saving maximum value;
 **
 */

void     ft_find_bones(t_vars *psv)
{
	ft_quick_sort(psv->arr, 0, psv->qa);
	int i;
	i = 1;
	psv->mass[0] = psv->arr[1];
	psv->mass[1] = psv->arr[psv->qa / 2];
	psv->mass[2] = psv->arr[psv->qa];
}
