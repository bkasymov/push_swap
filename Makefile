NAMEPS = push_swap
NAMECH = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC1 = ./src/push_swap.c \
		./src/parser/init_array.c \
	  ./src/parser/parsing_utils.c \
	  ./src/parser/parsing_utils2.c \
	  ./src/parser/ft_check_dupl.c \
	  ./src/parser/ft_check_sort.c \
	  ./src/rules/rules_ss.c \
	  ./src/rules/rules_pp.c \
	  ./src/rules/rules_rr.c \
	  ./src/rules/rules_rrr.c \
	  ./src/solver/ft_solver_ps.c \
	  ./src/solver/ft_quick_sort_arr.c \
	  ./src/solver/ft_generals_solvers_utils_ps.c \
	  ./src/parser/error_and_free.c \
	  ./src/solver/ft_general_solver_ps.c \
	  ./src/solver/ft_generals_solvers_utils2_ps.c

SRC2 = ./src/checker.c \
		./src/parser/init_array.c \
	  ./src/parser/parsing_utils.c \
	  ./src/parser/parsing_utils2.c \
	  ./src/parser/ft_check_dupl.c \
	  ./src/parser/ft_check_sort.c \
	  ./src/parser/error_and_free.c \
	  ./src/rules/rules_ss.c \
	  ./src/rules/rules_pp.c \
	  ./src/rules/rules_rr.c \
	  ./src/rules/rules_rrr.c

OBJS1 = $(SRC1:.c=.o)
OBJS2 = $(SRC2:.c=.o)

HEAD = -I./includes/push_swap.h
LIBFT_HEAD = -I ./libft/includes/libft.h
LIBFT_BIN = -L./libft -lft
LIBFT = ./libft/libft.a

all: $(LIBFT) ./libft/libft.a  $(NAMEPS) $(NAMECH)

FORCE:		;

LIBFT		= ./libft/libft.a

$(LIBFT):		FORCE
	@make -C libft

%.o: %.c
	gcc $(FLAGS) $(HEAD) $(LIBFT_HEAD) -c $< -o $@

$(NAMEPS): $(OBJS1) $(LIBFT) ./includes/push_swap.h
	gcc $(FLAGS) $(OBJS1) $(LIBFT_BIN) -o $@

$(NAMECH): $(OBJS2) $(LIBFT) ./includes/push_swap.h
	gcc $(FLAGS) $(OBJS2) $(LIBFT_BIN) -o $@

clean:
	/bin/rm -f $(OBJS1) $(OBJS2)
	make -C ./libft fclean

fclean: clean
	/bin/rm -f $(NAMEPS)
	/bin/rm -f $(NAMECH)

re: fclean all

.PHONY: all, clean, fclean, re
