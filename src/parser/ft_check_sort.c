/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:48:48 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:25:57 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** This function will check the order of the digits.
** if all digits in right order, we should to return nothing.
** in cycle launching my array, where all digits.
** if even next digit bigger than current digit, we are counting
** it like iteration. After all we are comparing our iteretions
** if both iterations is equal it's mean that order is right.
*/

int			ft_check_sort(t_vars *psv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < psv->qa - 1)
	{
		if (psv->arr[i] < psv->arr[i + 1])
			j++;
		i++;
	}
	if (i == j)
	{
		ft_free_list(psv);
		return (1);
	}
	return (0);
}

int			ft_check_sort_ch(t_vars *psv)
{
	t_stack *buff;
	t_stack *first;

	first = psv->stack_a;
	buff = first;
	while (buff->next != NULL)
	{
		if (buff->data < buff->next->data)
			buff = buff->next;
		else
			return (0);
	}
	return (1);
}
