NAME = push_swap

COMPILE = gcc -g

SRC = ft_push_swap.c

INC = -I ./includes -I ./libft/ft_printf -I ./libft/ftoa

all: $(NAME)

$(NAME):
	make -C libft
	$(COMPILE) -Wextra -Werror $(SRC) $(INC) -L ./libft -lft

clean:
	rm -f ./libft/*.o
	rm -f ./libft/printf/*.o
	rm -f ./libft/ftoa/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/printf/libft.a

re: fclean all
