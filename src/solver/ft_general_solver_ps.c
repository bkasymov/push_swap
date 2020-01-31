#include "../../includes/push_swap.h"

/*
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

/*
 * We should to divide our digits to 2 colomns;
 * all numbers till medium - will have positive
 * digits because it's steps thant to put digit
 * by steps;
 * if digits after middle, all steps will be negative
 * because we will use ft_rra;
 * Короче делим числа стэка на двое.
 * Если это числа первой середины, то высчитываем сколько шагов
 * нужно, чтобы они стали на первую позицию. Вращение д.б.
 * вверх.
 * Если это числа второй середины, то крутим через ft_rra or ft_rrb
 * т.е. двигаем снизу.
 * Начинаем с -1, чтобы позиция первого элемента была ноль.
 * Ей ведь передвигаться не нужно.
 * */

void        ft_calc_step(t_stack *tmp, int quan)
{
	int     i;
	int     mid;
	t_stack  *list;

	i = -1;
	mid = quan / 2;
	list = tmp;
	while (mid >= i)
	{
		list->step = i;
		list->rotate = 1;
		tmp->next;
		i++;
	}
	if (quan % 2 == 0)
		i--;
	while (i > 0)
	{
		list->step = i;
		list->rotate = -1;
		list = list->next;
		i--;
	}
}

/*
 ** if digit of stack == max, our first maximum digit at first in stack and
 ** we are shifting up all elements by one. After it our max digit will be by end;
 **
 ** if max element on the second stage, we are shifting all elements by 1
 **
 ** And if first element more then last element, we are swaping this digits;
 * at first putting all digits which not max or min to stack_b
 * in cycle till qa > 2 we are checking next
 * if it's not max and min, ft_pb.
 * if digit > med, putting to stack_b by end through ft_pb and ft_rb;
 * if digit < med, just putting to stack_b;
 * if digit of stack_a is max or min, putting it by end of stack_a;
 * Taking from stack_b random element with list to stack_a;
 * Sending than to mark every list with necessary steps and rotations;
 * */

void        ft_lets_go(t_vars *psv)
{
	t_stack     *tmpa;
	t_stack     *tmpb;
	int         i;

	i = 0;
	tmpa = psv->stack_a;
	tmpb = psv->stack_b;
	while (psv->qa > i) {

	}
}

void        ft_general_solution(t_vars *psv)
{
	while (psv->qa > 2)
	{
		if (psv->stack_a->data != psv->mass[0] && psv->stack_a->data != psv->mass[2])
		{
			if (psv->stack_a->data > psv->mass[1])
			{
				ft_pb(psv, 1);
				ft_rb(psv, 1);
			}
			else
				ft_pb(psv, 1);
		}
		else
			ft_ra(psv, 1);
	}
	if (psv->stack_a->data < psv->stack_a->next->data)
		ft_sa(psv, 1);
	ft_calc_step(psv->stack_a, psv->qa);
	ft_calc_step(psv->stack_b, psv->qb);
	ft_lets_go(psv);
}

/*
 * in array all digits, in start a zero and in end the count of
 * digits;
 *
 */

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

/*
 * pivot it's last digit;
 *
 */

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
