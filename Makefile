NAME1 = push_swap
NAME2 = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC1 = ./src/push_swap.c \
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

SRC2 = ./src/checker.c \
	  ./src/parser/parsing_utils.c \
	  ./src/parser/parsing_utils2.c \
	  ./src/parser/ft_check_dupl.c \
	  ./src/parser/ft_is_it_sorted.c \
	  ./src/rules/rules_ss.c \
	  ./src/rules/rules_pp.c \
	  ./src/rules/rules_rr.c \
	  ./src/rules/rules_rrr.c

OBJSFD = object_files

OBJS1 = $(SRC1:.c=.o)
OBJS2 = $(SRC2:.c=.o)

HEAD = -I ./includes
LIBFT_HEAD = -I ./libft/includes
LIBFT_BIN = -L ./libft -lft
LIBFT = ./libft/libft.a

$(LIBFT):
	make -C libft

all: $(LIBFT) $(NAME1) $(NAME2)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJS1) $(OBJS2)
	$(CC) $(FLAGS) $(HEAD) $(LIBFT_HEAD) -c $< -o $@

$(NAME1): $(OBJS1) $(LIBFT)
	$(CC) $(OBJS1) $(LIBFT_BIN) -o $@

$(NAME2): $(OBJS2) $(LIBFT)
	$(CC) $(OBJS2) $(LIBFT_BIN) -o $@

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	make -C ./libft fclean

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all
