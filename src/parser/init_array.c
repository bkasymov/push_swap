/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:27:24 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:29:21 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			ft_init_array(t_vars *psv, int argc, int a)
{
	int		j;
	int		tmp;

	tmp = argc - 1;
	j = 0;
	if (!(psv->arr = (int *)malloc(sizeof(int) * (argc))))
		return (1);
	while (tmp >= j)
	{
		psv->arr[j] = 0;
		j++;
	}
	return (0);
}
