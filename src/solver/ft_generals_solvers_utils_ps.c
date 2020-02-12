#include "../../includes/push_swap.h"

/*
 * this function aligning all digits by order
 * if min digit close by start - doing ft_ra
 * else ft_rra
 * Doing it than to econom count of actions to align
 * by order.
 */

void        ft_align_in_order(t_vars *psv)
{
    int     i;
    int     j;
    t_stack *tmp;

    tmp = psv->stack_a;
    j = psv->qa / 2;
    i = 1;
    while (tmp->data != psv->mass[0])
    {
        tmp = tmp->next;
        i++;
    }
    if (i > j)
        while (psv->stack_a->data != psv->mass[0])
            ft_rra(psv, 1);
    else
        while (psv->stack_a->data != psv->mass[0])
            ft_ra(psv, 1);
}

/*
 * Goal of function is double checking founded
 * place with other each other places.
 * if have more suitable place - returning 1;
 */

int         ft_search_small_element(t_vars *psv, int *data, int data_b)
{
    t_stack *tmp;
    int     res;

    tmp = psv->stack_a;
    res = 0;
    while (res == 0 && tmp)
    {
        if (tmp->data < *data && tmp->data > data_b)
            res = 1;
        tmp = tmp->next;
    }
    return (res);
}

/*
 * Performing actions, which calculated from
 * ft_calc_place_for_insertion
 * If have action to turn - turn;
 * a_turn is rotation. If it is - turning ft_ra;
 * else ft_rra because value of turn is 1 or -1
 * (rotating with shift down);
 *
 */

void        ft_performance_actions(t_vars *psv, t_pos *pos)
{
    while (pos->a_quantity)
    {
        if (pos->a_turn)
            ft_ra(psv, 1);
        else
            ft_rra(psv, 1);
        pos->a_quantity--;
    }
    while (pos->b_quantity) {
        if (pos->b_turn)
            ft_rb(psv, 1);
        else
            ft_rrb(psv, 1);
        pos->b_quantity--;
    }
    ft_pa(psv, 1);
}

/*
 * ft_calc_step calculating how much steps
 * should be than to be at the top position
 * and set up rotation, which indicate which
 * rotation should be than to move by top
 * Rotation 1 mean ft_ra and -1 mean ft_rra
 * (shift up), (shift down);
*/

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
        list->rotation = 1;
        list = list->next;
        i++;
    }
    if (quan % 2 == 0)
        i--;
    while (--i > 0)
    {
        list->step = i;
        list->rotation = -1;
        list = list->next;
    }
}

/*
 ** psv->mass[0] saving minimum, [1] saving medium, [2] saving maximum value;
 */

void     ft_find_bones(t_vars *psv)
{
    int     i;

    i = 0;
    ft_quick_sort(psv->arr, i, psv->qa);
    psv->mass[0] = psv->arr[0];
    psv->mass[1] = psv->arr[psv->qa / 2];
    psv->mass[2] = psv->arr[psv->qa - 1];
}

