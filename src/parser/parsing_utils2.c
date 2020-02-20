/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 23:17:24 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/20 19:57:18 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** It's first checking of numbers. If something except numbers - error;
** && (str[i + 1] >= '0' && str[i + 1] <= '9'))))
*/

int			ft_check_sym(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit(str[i])) == 1 || (str[i] == ' ') || (str[i] == '-'))
		{
			if (str[i] == '-')
			{
				if (str[i + 1] >= '0' && str[i + 1] <= '9')
					i++;
				else
					return (1);
			}
			i++;
		}
		else
			return (1);
	}
	return (0);
}

/*
** performed copy of ft_atoi
** but specification of it that:
** 1. miss all 0 symbols before number;
** 2. if strings number more than int - calling error_print
*/

int			ft_atoips(t_vars *psv, const char *str)
{
	int				i;
	int				dec;
	int				sym;
	long			res;

	i = 0;
	sym = 1;
	res = 0;
	dec = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		sym = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		dec++;
		i++;
		if (dec > 10 || (res * sym) < -2147483648 || (res * sym) > 2147483647)
			error_print(psv, 0);
	}
	return (res * sym);
}
