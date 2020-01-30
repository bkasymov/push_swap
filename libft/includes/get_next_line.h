#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 9999
# define FD_MAX 100000

int		get_next_line(const int fd, char **line);

#endif