/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:50:59 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/12 13:35:27 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** At first we are finding max digit in stack_a
** Dividing solution to other 3 solutions;
** if digits 3, 5 or more;
*/

void		ft_solver_ps(t_vars *psv)
{
	if (psv->qa <= 3)
		ft_3args_solution(psv);
	else if (psv->qa <= 5)
	{
		ft_find_bones(psv);
		ft_5args_solution(psv);
	}
	else if (psv->qa > 5)
	{
		ft_find_bones(psv);
		ft_general_solution(psv);
	}
}

/*
** Finding max value in stack_a of last lists again,
** because last max value was pb to stack_b and we are
** finding new max value in fresh stack_a;
*/

int			ft_find_max(t_vars *psv)
{
	int		max_el;
	t_stack	*tmp;

	tmp = psv->stack_a;
	max_el = tmp->data;
	while (tmp)
	{
		if (tmp->data > max_el)
			max_el = tmp->data;
		tmp = tmp->next;
	}
	return (max_el);
}

void		ft_3args_solution(t_vars *psv)
{
	int		max_el;

	max_el = ft_find_max(psv);
	if (psv->qa == 1)
		return ;
	if (psv->qa == 2)
	{
		if (psv->stack_a->data > psv->stack_a->next->data)
			ft_sa(psv, 1);
		return ;
	}
	else if (psv->qa == 3)
	{
		if (psv->stack_a->data == max_el)
			ft_ra(psv, 1);
		if (psv->stack_a->next->data == max_el)
			ft_rra(psv, 1);
		if (psv->stack_a->data > psv->stack_a->next->data)
			ft_sa(psv, 1);
	}
}

/*
** a) max and min value putting to stack_b with cycle less 2;
** b) sending to sort of 3 element to function ft_3args_solution;
** c) after it returning back elements from stack_b to stack_a;
** d) if first element is max, using ft_ra than to put it to last list
** e) if first element is min, using ft_sa than to
** swap min and max values and ft_ra than to put max to last list;
*/

void		ft_5args_solution(t_vars *psv)
{
	while (psv->qb < 2)
	{
		if (psv->stack_a->data == psv->mass[0] || \
				psv->stack_a->data == psv->mass[2])
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
