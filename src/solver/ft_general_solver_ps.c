/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_solver_ps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:50:29 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/12 13:20:47 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Starting cycle of elements A;
** tmp saving data of first elem of A than to use it below;
** **************
** In variable "actions" counting how many lists missed than to
** find position for B's element in A;
** **************
** When we found position for list of B in A we are launching
** next part.
** ft_search_small_element checking A for elements which could
** be between current digits A and B.
** For example - we would like to ft_pa from B (444) to A (where
** 555-1000-111). We should check have A element between 444 and 555
** for instance - 446, or 499; If have, we are incrementing variable
** actions than to keep this number in top.
*/

void		ft_search_position(t_vars *psv, int *tmp, int *actions)
{
	while (psv->stack_a)
	{
		*tmp = psv->stack_a->data;
		if (psv->stack_a->data < psv->stack_b->data)
		{
			*actions = *actions + 1;
			if (psv->stack_a->next->data > psv->stack_b->data)
				break ;
			psv->stack_a = psv->stack_a->next;
		}
		else
			break ;
	}
	if (ft_search_small_element(psv, tmp, psv->stack_b->data))
	{
		while (psv->stack_a)
		{
			if (psv->stack_a->data < *tmp && \
				psv->stack_a->data > psv->stack_b->data)
				break ;
			else
				*actions = *actions + 1;
			psv->stack_a = psv->stack_a->next;
		}
	}
}

/*
** ft_search_and_calc_position's goal is to find element of B
** which have minimum operations to move to A;
** In ft_search_position we are searching position between random
** number and maximum and count of actions in "actions"
** "tmp" using in ft_search_position than to econom lines;
** If actions + steps of B bigger than min_oper (minimum operations),
** - missing record steps for perform and checking next element of B;
*/

int			ft__search_and_calc_position(t_vars *psv, t_pos *pos, int min_oper)
{
	int		tmp;
	int		actions;
	int		rec;

	tmp = 0;
	actions = 0;
	ft_search_position(psv, &tmp, &actions);
	if (psv->stack_a->rotation == -1) //????? For what?
		actions = psv->qa - actions;
	if (min_oper == -1 || (psv->stack_b->step + actions) < min_oper)
	{
		pos->a_rote = psv->stack_a->rotation;
		pos->b_rote = psv->stack_b->rotation;
		pos->a_shift = actions;
		pos->b_shift = psv->stack_b->step;
		rec = psv->stack_b->step + actions;
	}
	else
		return (min_oper);
	return (rec);
}

/*
** Goal of function is to calculate of actions
** to every list of stack_b;
** Variable acts saving a count of actions for every list;
** We are saving links of stacks, because stack_a will be update when
** using in ft_search_and_calc_position when searching position in stack_a;
** stack_b will be update too because giving data of it for comparison.
*/

void		ft_calc_place_for_insertion(t_vars *psv, t_pos *pos)
{
	int	acts;
	t_stack	*save_a;
	t_stack	*save_b;

	acts = -1;
	save_a = psv->stack_a;
	save_b = psv->stack_b;
	while (psv->stack_b)
	{
		acts = ft__search_and_calc_position(psv, pos, acts);
		psv->stack_a = save_a;
		psv->stack_b = psv->stack_b->next;
	}
	psv->stack_b = save_b;
}

/*
** Initializing positions variable than to keep
** there information about calculation of steps for
** every digit to move values from stack b to stack a.
** Allocating memory than to spend less memory for
** performance of program.
** start value of ?_quantity is -1 than to
** save of mistakes of calc steps;
** When all digits pushed to stack_a - we should to sort
** stack_a by order;
*/

void		ft_general_sort(t_vars *psv)
{
	t_pos	pos;

	while (psv->qb != 0)
	{
	        pos.a_rote = 0;
	        pos.b_rote = 0;
		pos.a_shift = -1;
		pos.b_shift = -1;
		ft_calc_step(psv->stack_a, psv->qa);
		ft_calc_step(psv->stack_b, psv->qb);
		ft_calc_place_for_insertion(psv, &pos);
		ft_performance_actions(psv, &pos);
	}
	ft_align_in_order(psv);
}

/*
** All digitals with the exception of min and max values
** pushing to stack_b;
** if digit less than medium value - pushing by begining;
** if digit bigger than medium value - pushing by begining
** and shifting down with ft_rb;
** pushing from stack_b to stack_a random number
** for comparing of next algorithm;
*/

void		ft_general_solution(t_vars *psv)
{
	while (psv->qa > 2)
	{
		if (psv->stack_a->data != psv->mass[0] && \
				psv->stack_a->data != psv->mass[2])
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
