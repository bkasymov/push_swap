/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:50:54 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:19:46 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_quick_sort sending to ft_qs2
** at first comparing first and last number
** if first number is less than last - it's OK;
** if first number is bigger than last - missing.
** if next number is less than last - saving first number
** and put by first a number which less than last;
** so we are moving numbers of start to end.
*/

#include "../../includes/push_swap.h"

int			ft_qs(int *array, int start, int end)
{
	int		pivot;
	int		i;
	int		temp;
	int		j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}

void		ft_quick_sort(int *array, int start, int end)
{
	int q;

	q = 0;
	if (start < end)
	{
		q = ft_qs(array, start, end);
		ft_quick_sort(array, start, q - 1);
		ft_quick_sort(array, q + 1, end);
	}
	else
		return ;
}
