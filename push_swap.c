#include "stdio.h" 
#include "unistd.h"
#include "push_swap.h"

int             ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

void	error_print(void)
{
		ft_printf("Error\n");
}

int		ft_check_string(char *str)
{
	int		i;

	i = 0;
	while(*str)
	{
		if (ft_isdigit(*str) == 0)
		{
			error_print();
			return(1);
		}
		*str++;
	}
	return(0);
}

int		ft_args_in_1_string(char *str)
{
	int		res;

	res = 0;
	if ((res = ft_check_string(str)) == 1)
		return(1);
}

/*
 ** Program getting argument and checking.
 ** if 2 argument - dividing string to separate array strings,
 ** check all string that it's all numbers and after it converting to
 ** integer type and recording to stack a;
 ** if argument just 1 or less - finishing work;
 ** else every argument getting separate - checking that all arguments are digits and
 ** recording to array

** code which split our string to separate string with numbers
** after it check array and confident that every symbols are digits,
** without any other.
** after it through ft_atoi will convert to numbers and record to stack.
** and free result of ft_strsplit
*/

int		main(int argc, char **argv)
{
	int     *a;
	int     *b;

	if (argc == 2)
		return(ft_args_in_1_string(argv[1]));
	return(0);
}
