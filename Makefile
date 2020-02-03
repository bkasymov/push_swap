NAME_PS = push_swap

NAME_CH = checker

SRC = ./src/push_swap.c \
	  ./src/parser/parsing_utils.c \
	  ./src/parser/parsing_utils2.c \
	  ./src/parser/ft_check_dupl.c \
	  ./src/parser/ft_is_it_sorted.c \
	  ./src/rules/rules_ss.c \
	  ./src/rules/rules_pp.c \
	  ./src/rules/rules_rr.c \
	  ./src/rules/rules_rrr.c \
	  ./src/solver/ft_solver_ps.c \
	  ./src/solver/ft_general_solver_ps.c

SRC_CH = ./src/checker.c \
	  ./src/parser/parsing_utils.c \
	  ./src/parser/parsing_utils2.c \
	  ./src/parser/ft_check_dupl.c \
	  ./src/parser/ft_is_it_sorted.c \
	  ./src/rules/rules_ss.c \
	  ./src/rules/rules_pp.c \
	  ./src/rules/rules_rr.c \
	  ./src/rules/rules_rrr.c

OBJ = $(SRC:.c=.o)

OBJ_CH = $(SRC_CH:.c=.o)

OBJ_LIB = ./libft/*.o

HEAD = -I ./includes/push_swap.h  ./libft/ft_printf  ./libft/ftoa  ./src/rules/rules.h

FLAGS = -Wall -Wextra -Werror

LIBINC = -I libft/include/libft.h -L ./libft -lft

LIBFT = ./libft/libft.a

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJ) $(LIBFT)
	make -C libft/
	gcc $(FLAGS) $(OBJ) $(OBJ_LIB) $(LIBINC) $(LIBFT) -o $(NAME_PS)

$(NAME_CH): $(OBJ_CH) $(LIBFT)
	gcc $(FLAGS) $(OBJ_CH) $(OBJ_LIB) $(LIBINC) $(LIBFT) -o $(NAME_CH)

clean:
	rm -f ./libft/*.o
	rm -f ./libft/printf/*.o
	rm -f ./libft/ftoa/*.o
	rm -f $(OBJ)
	rm -f $(OBJ_CH)

fclean: clean
	rm -f $(NAME_CH)
	rm -f $(NAME_PS)
	rm -f libft/printf/libft.a

re: fclean all
