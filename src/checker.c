/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:47:50 by dpenney           #+#    #+#             */
/*   Updated: 2020/02/16 18:30:21 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_performing_rules(char *line, t_vars *chv)
{
	if (ft_strcmp(line, "ra") == 0)
		ft_ra(chv, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(chv, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(chv, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(chv, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(chv, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(chv, 0);
	else if (ft_strcmp(line, "sa") == 0)
		ft_sa(chv, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(chv, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(chv, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(chv, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(chv, 0);
	else
		error_print(chv, 0);
}

void		ft_read_rules(t_vars *chv)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "l") == 0)
			break ;
		ft_performing_rules(line, chv);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int			main(int argc, char **argv)
{
	t_vars	chv;

	if (argc >= 2)
	{
		if ((ft_general_parser(argc, argv, &chv)) == 1)
			return (1);
		ft_check_dupl(&chv);
		ft_read_rules(&chv);
		if (ft_check_sort_ch(&chv) && chv.qb == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free_list(&chv, 0);
		free(chv.arr);
	}
	return (0);
}
