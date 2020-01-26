#include "rules.h"

/*
 ** Rules for swap first elements of stacks;
 ** sa swap stack_a;
 ** sb swap stack_b;
 ** Copied first element of top stack_a to tmp;
 ** Same actions in ft_sb;
 ** Rule ss do ft_sa and ft_sb in one time;
 */

void        ft_sa(t_vars *psv, int ps)
{
	int     tmp;

	if (!psv->stack_a->next)
		return ;
	tmp = psv->stack_a->data;
	psv->stack_a->data = psv->stack_a->next->data;
	psv->stack_a->next->data = tmp;
	if (ps)
		write(1, "sa\n", 3);
}

void        ft_sb(t_vars *psv, int ps)
{
	int     tmp;

	if (!psv->stack_b->next)
		return ;
	tmp = psv->stack_b->data;
	psv->stack_b->data = psv->stack_b->next->data;
	psv->stack_b->next->data = tmp;
	if (ps)
		write(1, "sb\n", 3);
}

/*
 ** swap in stack_a and in stack_b;
 */

void        ft_ss(t_stack *psv, int ps)
{
	ft_sa(psv, ps);
	ft_sb(psv, ps);
	if (ps)
		write(1,"ss\n", 3);
}