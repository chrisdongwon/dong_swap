# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:08:28 by cwon              #+#    #+#              #
#    Updated: 2025/01/23 19:20:31 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_EXEC = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = \
	push_swap.h \
	doubly_linked_list.h \
	stack.h
SRC = \
	adjust.c \
	doubly_linked_list.c \
	init.c \
	minimum_rotation.c \
	push_swap.c \
	push.c \
	quicksort.c \
	reverse_rotate.c \
	rotate.c \
	stack.c \
	swap.c
OBJ = $(SRC:.c=.o)

BONUS_HEADER = checker_bonus.h
BONUS_SRC = \
	checker_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

bonus: $(BONUS_EXEC)

$(BONUS_EXEC): $(LIBFT) $(BONUS_OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_EXEC) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_EXEC)

re: fclean all

.PHONY: all clean fclean re bonus