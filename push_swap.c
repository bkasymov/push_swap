
#include "push_swap.h"

typedef struct node
{
	struct node		head;
	int				value;
	struct node		*next;
}					t_list;

void	fill_list();

int		init_list(int i, char *argv)
{
	t_list		*stack_a;


	stack_a->head = NULL;
	stack_a->value = 0;
	while(i > 0)
	{
		if(!(stack_a = (t_list *)ft_memalloc(sizeof(t_list))))
			return(1);
		stack_a->value = ft_atoi(argv[i]);
		stack_a->
		i--;
	}
	
}

int		error_print(void)
{
		ft_printf("Error");
		return (1);
}

int		main(int argc, char **argv)
{
	if (init_list(argc, argv) != 0)
		return (error_print);
	return (0);
}

