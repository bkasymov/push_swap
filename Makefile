NAME = push_swap

COMPILE = gcc

SRC = push_swap.c

INC = -I ./includes

all: $(NAME)

$(NAME):
	make -C libft
	$(COMPILE) $(SRC) $(INC)

clean:
	rm -f ./libft/*.o
	rm -f ./libft/printf/*.o
	rm -f ./libft/ftoa/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/printf/libftprintf.a
	
