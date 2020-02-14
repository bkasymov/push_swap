/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:50:54 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/12 13:30:13 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


//void        ft_quick_sort(int *s_arr, int first, int last)
//{
//  int left;
//  int right;
//  int middle;
//  int tmp;
//
//  left = first;
//  right = last - 1;
//  middle = s_arr[(left + right) / 2];
//  if (first < last) {
//    while (s_arr[left] < middle)
//      left++;
//    while (s_arr[right] > middle)
//      right--;
//    while (left <= right) {
//      if (left <= right) {
//        tmp = s_arr[left];
//        s_arr[left] = s_arr[right];
//        s_arr[right] = tmp;
//        left++;
//        right--;
//      }
//      ft_quick_sort(s_arr, first, right);
//      ft_quick_sort(s_arr, left, last);
//    }
//  }
//}


int			ft_partition(int *array, int start, int end)
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
		q = ft_partition(array, start, end);
		ft_quick_sort(array, start, q - 1);
		ft_quick_sort(array, q + 1, end);
	} else
	  return ;
}
