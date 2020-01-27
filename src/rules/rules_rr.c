#include "rules.h"

/*
 ** taking first list with first element to tmp variable
 ** Finding last element through cycle;
 ** Zeroing next element of tmp;
 ** last list will indicate to tmp;
 ** first element take address of second element;
 */

void        ft_ra(t_vars *psv, int ps)
{
	t_stack *first;
	t_stack *tmp;
	t_stack *last;

	tmp = psv->stack_a;
	last = psv->stack_a;
	first = psv->stack_a->next;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	psv->stack_a = first;
	if (ps)
		write(1, "ra\n", 3);
}

void        ft_rb(t_vars *psv, int ps)
{
	t_stack *first;
	t_stack *tmp;
	t_stack *last;

	tmp = psv->stack_b;
	last = psv->stack_b;
	first = psv->stack_b->next;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	psv->stack_b = first;
	if (ps)
		write(1, "rb\n", 3);
}

/*
 ** doing ra and rb together;
 */

void        ft_rr(t_vars *psv, int ps)
{
	ft_ra(psv, 1);
	ft_rb(psv, 1);
	if (ps)
		write(1,"rr\n", 3);
}
