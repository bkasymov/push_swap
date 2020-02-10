#include "../../includes/push_swap.h"

/*
 * in array all digits, in start a zero and in end the count of
 * digits;
 *
 */

void        ft_quick_sort(int *s_arr, int first, int last)
{
    int left;
    int right;
    int middle;
    int tmp;

    left = first;
    right = last - 1;
    middle = s_arr[(left + right) / 2];
    while (s_arr[left] < middle)
        left++;
    while (s_arr[right] > middle)
        right--;
    while (left <= right)
    {
        if (left <= right)
        {
            tmp = s_arr[left];
            s_arr[left] = s_arr[right];
            s_arr[right] = tmp;
            left++;
            right--;
        }
        ft_quick_sort(s_arr, first, right);
        ft_quick_sort(s_arr, left, last);
    }
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
    t_stack *list;

    list = tmp;
    i = 0;
    mid = quan / 2;
    while (mid >= i)
    {
        list->step = i;
        list->rotate = 1;
        list = list->next;
        i++;
    }
    if (quan % 2 == 0)
        i--;
    while (--i > 0)
    {
        list->step = i;
        list->rotate = -1;
        list = list->next;
    }
}


void        ft_general_sort(t_vars *psv)
{
    while (psv->qb > 0)
    {

        ft_calc_step(psv->stack_a, psv->qa);
        ft_calc_step(psv->stack_b, psv->qb);
    }
}

/*
 * All digitals with the exception of min and max values
 * pushing to stack_b;
 * if digit less than medium value - pushing by begining;
 * if digit bigger than medium value - pushing by begining and shifting down with ft_rb;
 * pushing from stack_b to stack_a random number for comparing of next algorithm;
 */

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
    ft_pa(psv, 1);
    ft_general_sort(psv);
}

/*
 ** psv->mass[0] saving minimum, [1] saving medium, [2] saving maximum value;
 */



void     ft_find_bones(t_vars *psv)
{
	ft_quick_sort(psv->arr, 0, psv->qa);
	psv->mass[0] = psv->arr[0];
	psv->mass[1] = psv->arr[psv->qa / 2];
	psv->mass[2] = psv->arr[psv->qa - 1];
}









