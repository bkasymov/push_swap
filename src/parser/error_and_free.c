/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:30:03 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:28:17 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/push_swap.h"

void		ft_free_list(t_vars *psv, int a)
{
	t_stack	*tmp;

	while (psv->stack_a)
	{
		tmp = psv->stack_a;
		psv->stack_a = psv->stack_a->next;
		free(tmp);
	}
	if (psv->stack_b)
	{
		while (psv->stack_b)
		{
			tmp = psv->stack_b;
			psv->stack_b = psv->stack_b->next;
			free(tmp);
		}
	}
}

/*
** function which print Error message;
** free stacks variables;
** write "Error";
*/

void		error_print(t_vars *psv, int a)
{
	if (a)
		ft_free_list(psv, 1);
	free(psv->arr);
	write(1, "Error\n", 7);
	exit(1);
}
