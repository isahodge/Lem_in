# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 14:20:14 by aderby            #+#    #+#              #
#    Updated: 2017/12/05 19:19:44 by aderby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
C_FIL = additional_parsing.c algo.c astar_struct_init.c create_nodes.c \
		hash_function.c linker.c main.c parse_data.c parse_helpers.c \
		print_ants.c queue.c stack.c free.c visited_nodes.c
O_FIL = ${C_FIL:.c=.o}
O_LOC = obj
GCC_FLAGS = gcc -Wall -Wextra -Werror -g
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(O_FIL)
		cd libft && make re
		$(GCC_FLAGS) $(LIB) $(O_FIL) -o $(NAME)
		@echo "This corrector is the best person ever"

%.o: %.c
	$(GCC_FLAGS) -c $< -o $@

clean:
		-@rm $(O_FIL) 2>/dev/null || true
		cd libft && make clean

fclean: clean
		cd libft && make fclean
		/bin/rm -f $(NAME)

re: fclean all
