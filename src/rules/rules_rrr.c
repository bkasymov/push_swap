#include "rules.h"

/*
 ** reverse rotate stacks elements
 ** shift down all elements of stacks by 1;
 ** the last element becomes the first one.
 */

void        ft_rra(t_vars *psv, int ps)
{
	t_stack *first;
	t_stack *tmp;
	t_stack *last;

	if (!psv->stack_a->next)
		return ;
	first = psv->stack_a;
	last = psv->stack_a;
	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = first;
	psv->stack_a = tmp;
	if (ps)
		write(1, "rra\n", 4);
}

void        ft_rrb(t_vars *psv, int ps)
{
	t_stack *first;
	t_stack *tmp;
	t_stack *last;

	first = psv->stack_b;
	last = psv->stack_b;
	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = first;
	psv->stack_b = tmp;
	if (ps)
		write(1, "rrb\n", 4);
}

void        ft_rrr(t_vars *psv, int ps)
{
	ft_rra(psv, 1);
	ft_rrb(psv, 1);
	if (ps)
		write(1, "rrr\n", 4);
}