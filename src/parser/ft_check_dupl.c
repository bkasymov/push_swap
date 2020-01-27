/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dupl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:05:28 by dpenney           #+#    #+#             */
/*   Updated: 2020/01/13 17:09:01 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/push_swap.h"

/*
 * Not working cycle when looking for duplicate of digits.
 */

void		ft_check_dupl(t_vars *psv)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < psv->qa)
	{
		tmp = psv->arr[i];
		j = i + 1;
		while (j < psv->qa)
		{
			if (psv->arr[j] == tmp)
				error_print(psv);
			j++;
		}
		i++;
	}
}
