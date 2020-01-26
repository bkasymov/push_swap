#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/includes/libft.h"
# include "../src/rules.h"
# include "stdio.h" //Delete it!
# include "stdlib.h"
# include "unistd.h"
# include "../libft/ft_printf/printf.h"
# include "limits.h"


typedef		struct stacks
{
	struct stacks	*next;
	int				data;
	int             step;
}					t_stack;

typedef		struct variables_ps
{
	t_stack		        *stack_a;
	t_stack		        *stack_b;
	int			*a;
	int			*b;
	int                     count;
	int			j;
	int			res;
	int                     qa;
	int                     qb;
}				t_vars;

void	error_print(t_vars *psv);
int		ft_atoips(t_vars *psv, const char *str);
int		ft_check_sym(char *str);
int		ft_args_in_1_string(char *str, t_vars *psv);
int		ft_args_in_other_strings(char **argv, int argc, t_vars *psv);

/*
 * How to check duplicate?
 */

void		ft_check_dupl(t_vars *psv);

/*
 * Functions for record from array to list
 */

void            ft_init_lists(t_vars *psv, int mem);
t_stack         *ft_malloc_list(t_vars *psv, int mem);
void            ft_free_list(t_vars *psv);

/*
 * Performing rule swap two first elements;
 */

void        ft_sa(t_vars *psv, int ps);
void        ft_sb(t_vars *psv, int ps);
void        ft_ss(t_stack *psv, int ps);

/*
 ** Performing rule pp of take on element of one stack and put to the top of other one stack
 */

void        ft_pb(t_vars *psv, int ps);
void        ft_pa(t_vars *psv, int ps);

/*
 ** Performing functions rr
 */

void        ft_ra(t_vars *psv, int ps);
void        ft_rb(t_vars *psv, int ps);
void        ft_rr(t_vars *psv, int ps);

/*
 ** Performing functions rrr
 */

void        ft_rra(t_vars *psv, int ps);
void        ft_rrb(t_vars *psv, int ps);
void        ft_rrr(t_vars *psv, int ps);

/*
 ** Solution of push_swap
 */

void        ft_solution_ps(t_vars *psv);
void        ft_3args_solution(t_vars *psv, int max);
void        ft_5args_solution(t_vars *psv, int max);
void        ft_general_solution(t_vars *psv, int max);
int         ft_find_max(t_vars *psv);

#endif
