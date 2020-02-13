/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:40:39 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/12 13:38:12 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

/*
** Program getting argument and checking.
** if 2 argument - dividing string to separate array strings,
** check all string that it's all numbers and after it converting to
** integer type and recording to stack a;
** if argument just 1 or less - finishing work;
** else every argument getting separate - checking
** that all arguments are digits and
** recording to array
** code which split our string to separate string with numbers
** after it check array and confident that every symbols are digits,
** without any other.
** after it through ft_atoi will convert to numbers and record to stack
** and free result of ft_strsplit
*/

int			main(int argc, char **argv)
{
	t_vars	psv;
    psv.count = 0;

	if (argc < 2)
		return (0);
	if (((ft_general_parser(argc, argv, &psv)) == 1))
		return (1);
	if (ft_check_sort(&psv))
		return (0);
	ft_check_dupl(&psv);
	ft_solver_ps(&psv);
	ft_free_list(&psv, 1);
	return (0);
}
