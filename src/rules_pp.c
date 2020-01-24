# include "rules.h"

/*
 ** ft_pa take the first element of stack_b and
 ** put it at the top of stack_a;
 ** in tmp we are saving the top element of stack_b
 ** and moving forward stack_b to next element;
 ** Moving forward top element of stack_a and
 ** put at top the element of tmp;
 */

void    ft_pa(t_vars *psv, int ps)
{
	t_stack     *tmp;

	if (!(psv->stack_b))
		return ;
	psv->qa++;
	psv->qb--;
	tmp = psv->stack_b;
	psv->stack_b = psv->stack_b->next;
	tmp->next = psv->stack_a;
	psv->stack_a = tmp;
	if (ps)
		write(1, "pa\n", 3);
}

/*
 * push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
 * And to upper all digits to up;
 */

void        ft_pb(t_vars *psv, int ps)
{
	t_stack     *tmp;

	if (!psv->stack_a) // для чего так?
		return ;
	psv->qa--;
	psv->qb++;
	tmp = psv->stack_a;
	psv->stack_a = psv->stack_a->next;
	tmp->next = psv->stack_b;
	psv->stack_b = tmp;
	if (ps)
		write(1, "pb\n", 3);
}
