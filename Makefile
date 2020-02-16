NAME1 = push_swap
NAME2 = checker

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

$(LIBFT):
	make -C libft

all: $(LIBFT) $(NAME1) $(NAME2)

$(NAME1): $(OBJS1) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS1) $(LIBFT_BIN) -o $@

$(NAME2): $(OBJS2) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS2) $(LIBFT_BIN) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

clean:
	rm -f $(OBJS1) $(OBJS2)
	make -C ./libft fclean

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

.PHONY: all, clean, fclean, re
