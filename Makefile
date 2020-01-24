# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpenney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 14:41:08 by dpenney           #+#    #+#              #
#    Updated: 2020/01/13 15:06:34 by dpenney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = push_swap

SRC = ./src/push_swap.c \
	  ./src/parser/parsing_utils.c \
	  ./src/parser/parsing_utils2.c \
	  ./src/rules_ss.c \
	  ./src/rules_pp.c \
	  ./src/ft_check_dupl.c \
	  ./src/ft_rr.c \
	  ./src/ft_rrr.c

OBJ = $(SRC:.c=.o)

HEAD = -I ./includes/push_swap.h  ./libft/ft_printf  ./libft/ftoa  ./src/rules/rules.h

FLAGS = -Wall -Wextra -Werror

LIBINC = -I libft/include/libft.h -L ./libft -lft

all: $(NAME_1)

$(NAME_1): $(OBJ)
	make -C libft/
	gcc  $(OBJ) -I ./includes/ -o  $(NAME_1) $(LIBINC)

clean:
	rm -f ./libft/*.o
	rm -f ./libft/printf/*.o
	rm -f ./libft/ftoa/*.o
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft/printf/libft.a

re: fclean all
