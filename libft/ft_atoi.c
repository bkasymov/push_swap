/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oformi_ft_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:07:20 by dpenney           #+#    #+#             */
/*   Updated: 2019/12/24 16:45:02 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

#include "stdio.h"

int					ft_atoi(const char *str)
{
	size_t					i;
	int						sym;
	int	res;

	i = 0;
	sym = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		sym = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == 0)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
		if (i > 10 || (res * sym) < INT_MIN || (res * sym) > INT_MAX)
			ft_printf("Error");
	}
	return (res * sym);
}
