/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_solvers_utils2_ps.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:43:08 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:47:16 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** If we have digit which value is between first element of A
** and element for insert from B - we are calculating how much ft_ra or
** ft_rra we should to do than to put our digit before this small element;
*/

void		ft_calculate_small_element(t_vars *psv, int *tmp, int *actions)
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
