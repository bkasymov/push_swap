/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:49:56 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:20:55 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Rules for swap first elements of stacks;
** sa swap stack_a;
** sb swap stack_b;
** Copied first element of top stack_a to tmp;
** Same actions in ft_sb;
** Rule ss do ft_sa and ft_sb in one time;
*/

void		ft_sa(struct variables *psv, int ps)
{
	int		tmp;
	t_stack	*link;

	link = psv->stack_a;
	if (!link)
		return ;
	tmp = link->data;
	link->data = link->next->data;
	link->next->data = tmp;
	psv->count += 1;
	if (ps)
		write(1, "sa\n", 3);
}

void		ft_sb(struct variables *psv, int ps)
{
	int		tmp;
	t_stack	*link;

	link = psv->stack_b;
	if (!link)
		return ;
	tmp = link->data;
	link->data = link->next->data;
	link->next->data = tmp;
	psv->count += 1;
	if (ps)
		write(1, "sb\n", 3);
}

/*
** swap in stack_a and in stack_b;
*/

void		ft_ss(t_vars *psv, int ps)
{
	if (ps)
	{
		ft_sa(psv, 1);
		ft_sb(psv, 1);
	}
	else
	{
		ft_sa(psv, 0);
		ft_sb(psv, 0);
	}
	psv->count += 1;
	if (ps)
		write(1, "ss\n", 3);
}
