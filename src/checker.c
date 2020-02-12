#include "../includes/push_swap.h"
#include "stdio.h"

void    ft_performing_rules(char *line, t_vars *chv)
{
	if (!(ft_strcmp(line, "sa")))
		ft_sa(chv, 0);
	else if (!(ft_strcmp(line, "sb")))
		ft_sb(chv, 0);
	else if (!(ft_strcmp(line, "ss")))
		ft_ss(chv, 0);
	else if (!(ft_strcmp(line, "ra")))
		ft_ra(chv, 0);
	else if (!(ft_strcmp(line, "rb")))
		ft_rb(chv, 0);
	else if (!(ft_strcmp(line, "rr")))
		ft_rr(chv, 0);
	else if (!(ft_strcmp(line, "rra")))
		ft_rra(chv, 0);
	else if (!(ft_strcmp(line, "rrb")))
		ft_rrb(chv, 0);
	else if (!(ft_strcmp(line, "rrr")))
		ft_rrr(chv, 0);
	else if (!(ft_strcmp(line, "pa")))
		ft_pa(chv, 0);
	else if (!(ft_strcmp(line, "pb")))
		ft_pb(chv, 0);
	else
		error_print(chv, 0);
}

void    ft_read_rules(t_vars *chv)
{
	char    *line;

	line = NULL;
	while (get_next_line(0, &line))
	{
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


int     main(int argc, char **argv)
{
    t_vars      chv;

    if (argc == 2) {
        if ((ft_general_parser(argc, argv, &chv)) == 1)
            return (1);
        if (ft_check_sort(&chv))
            return (0);
        ft_check_dupl(&chv);
        ft_read_rules(&chv);
        if (ft_check_sort(&chv))
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
        ft_free_list(&chv, 0);
    }
    return (0);
}