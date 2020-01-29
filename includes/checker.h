#ifndef CHECKER_PS
# define CHECKER_PS

# include "../libft/includes/libft.h"
# include "../src/rules/rules.h"

#include "stdio.h"

# include "stdlib.h"
# include "unistd.h"
# include "../libft/ft_printf/printf.h"
# include "limits.h"

typedef		struct stacks_chv
{
	struct stacks	*next;
	int				data;
	int             step;
	int             rotate;
}					t_stack_chv;

/*
 ** mass variable keeping max digit[2], middle digit[1] and min digit[0]
 */

typedef		struct variables_chv
{
	t_stack		        *stack_a;
	t_stack		        *stack_b;
	int			        *arr;
	int                 count;
	int                 mass[3];
	int                 qa;
	int                 qb;
}				        t_vars_chv;

int                     ft_general_parser(int argc, char **argv, t_vars *psv);
void	                error_print(t_vars *psv);
int		                ft_atoips(t_vars *psv, const char *str);
int		                ft_check_sym(char *str);
int		                ft_args_in_1_string(char *str, t_vars *psv);
int                     ft_args_in_other_strings(char **argv, int argc, t_vars *psv);

/*
 * How to check duplicate?
 */

void		            ft_check_dupl(t_vars *psv);

/*
 * Functions for record from array to list
 */

void                    ft_init_lists(t_vars *psv, int mem);
t_stack                 *ft_malloc_list(t_vars *psv, int mem);
void                    ft_free_list(t_vars *psv);
int                     ft_is_it_sorted(t_vars *psv);

/*
 * Performing rule swap two first elements;
 */

void                    ft_sa(t_vars *psv, int ps);
void                    ft_sb(t_vars *psv, int ps);
void                    ft_ss(t_vars *psv, int ps);

/*
 ** Performing rule pp of take on element of one stack and put to the top of other one stack
 */

void                    ft_pb(t_vars *psv, int ps);
void                    ft_pa(t_vars *psv, int ps);

/*
 ** Performing functions rr
 */

void                    ft_ra(t_vars *psv, int ps);
void                    ft_rb(t_vars *psv, int ps);
void                    ft_rr(t_vars *psv, int ps);

/*
 ** Performing functions rrr
 */

void                    ft_rra(t_vars *psv, int ps);
void                    ft_rrb(t_vars *psv, int ps);
void                    ft_rrr(t_vars *psv, int ps);

/*
** Finding max, med, min;
*/

void                    ft_find_bones(t_vars *psv);
void                    ft_quick_sort(int *array, int start, int end);
int                     ft_parting(int *array, int start, int end);
void                    ft_calc_step(t_stack *tmp, int quan);

#endif