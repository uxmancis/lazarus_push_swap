# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 14:21:32 by uxmancis          #+#    #+#              #
#    Updated: 2023/10/15 17:42:52 by uxmancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# Source files and object files
SRC = main.c push_swap.c check_errors.c fill_stack.c ft_sort_exceptions.c sort_it.c get_numof_moves.c get_travel_nb.c exec_moves.c 2s_moves.c decide_moves.c moves.c utils.c utils2.c utils3.c utils4.c utils5.c utils6.c
OBJ = $(SRC:.c=.o)

# Executable name
NAME = push_swap

# Make all rule
all: $(NAME)

# Build the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ)

# Clean everything, including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
