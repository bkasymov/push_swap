#include "rules.h"

void     ft_rule_swap(int *array, int qa)
{
	int     i;
	int     tmp;

	i = qa;
	if (qa < 2)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
}

void    ft_rule_swap_a(t_vars *psv)
{
	printf("Find this %d\n", psv->qa);
	ft_rule_swap(psv->a, psv->qa);
}

void    ft_rule_swap_b(t_vars *psv)
{
	ft_rule_swap(psv->b, psv->qb);
}

void    ft_rule_ss(t_vars *psv)
{
	ft_rule_swap(psv->a, psv->qa);
	ft_rule_swap(psv->b, psv->qb);
}