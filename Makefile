NAME = push_swap

COMPILE = gcc -g

SRC = ./src/ft_push_swap.c ./src/parser/parsing_utils.c ./src/parser/parsing_utils2.c ./src/parser/ft_check_duplicates.c ./src/rules/rules_ss.c

INC = -I ./includes -I ./libft/ft_printf -I ./libft/ftoa -I ./src/rules/rules.h

all: $(NAME)

$(NAME):
	make -C libft
	$(COMPILE) $(SRC) $(INC) -L ./libft -lft

clean:
	rm -f ./libft/*.o
	rm -f ./libft/printf/*.o
	rm -f ./libft/ftoa/*.o
	rm -f ./src/parser/*.o
	rm -f ./src/rules/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/printf/libft.a

re: fclean all
