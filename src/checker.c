#include "../includes/push_swap.h"

int     main(int argc, char **argv)
{
	t_vars      chv;
	char        **line;

	line = (char **)malloc(sizeof(char) * 10000);
	if ((ft_general_parser(argc, argv, &chv)) == 1)
		return (1);
	get_next_line(0, line);
}