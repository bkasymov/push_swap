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
** ft_search_small_element
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
** At first ft_search_position returning quantity of
** actions of element of stack_b which should to do
** than to be in order of stack_a;
** "tmp" is variable for function ft_search_position, not using here
** We are using it there than to keep number in this variable;
** not using here.
** After it checking a minimum action via
** comparing result of addition of actions and steps of
** current number;
** If it's more than minimum (calc variable), it's mean
** that position found.
** we are recording results in pos structure of variables
** than to perform this instruction in next func.
** Recording count of rotate to a_turn for put current digit
** of stack_b to top position.
** How it is working?
** Digit which less than current number of
** stack_b will be in down, digit of stack_b at the top and digit bigger than
** current digit of stack_b will be next after top position.
** b_turn counting how much rotation should be to move necessary element of
** stack_b to top than to use ft_pa (put top element of stack_b to stack_a;
** Else signaling via assigning value of min to rec and returning;
*/

int			ft__search_and_calc_position(t_vars *psv, t_pos *pos, int calc)
{
	int		tmp;
	int		actions;
	int		rec;

	tmp = 0;
	actions = 0;
	ft_search_position(psv, &tmp, &actions);
	if (psv->stack_a->rotation == -1)
		actions = psv->qa - actions;
	if (calc == -1 || (psv->stack_b->step + actions) < calc)
	{
		pos->a_turn = psv->stack_a->rotation;
		pos->b_turn = psv->stack_b->rotation;
		pos->a_quantity = actions;
		pos->b_quantity = psv->stack_b->step;
		rec = psv->stack_b->step + actions;
	}
	else
		return (calc);
	return (rec);
}

/*
** Goal of function is to calculate of actions
** to every list of stack_b;
** Variable acts saving a count of actions for every list;
** We are saving links of stacks, becaus stack_a will be update because
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
	while (psv->qb)
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
	        pos.a_turn = 0;
	        pos.b_turn = 0;
		pos.a_quantity = -1;
		pos.b_quantity = -1;
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
