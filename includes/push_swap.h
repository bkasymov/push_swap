#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/includes/libft.h"
# include "stdio.h" //Delete it!
# include "stdlib.h"
# include "unistd.h"
# include "../libft/ft_printf/printf.h"
# include <limits.h>

typedef		struct stacks
{
	int			*a;
	int			*b;
	int         count;
	int			j;
	int			res;
}				t_stacks;

void	error_print(t_stacks *vars);
int		ft_atoips(t_stacks *vars, const char *str);
int     ft_check_duplicates(t_stacks *vars, int argc);
int		ft_first_check(char *str);
int		ft_args_in_1_string(char *str, t_stacks *vars);
int		ft_args_in_other_strings(char **argv, int argc, t_stacks *vars);



#endif
