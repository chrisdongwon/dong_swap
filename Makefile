# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:53:51 by cwon              #+#    #+#              #
#    Updated: 2024/12/08 23:30:45 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

src = \
	list.c \
	stack.c \
	stack_util.c \
	target.c \
	target_util.c \
	swap.c \
	push.c \
	rotate.c \
	reverse.c

mandatory_src = \
	manual_sort.c \
	best_location.c \
	minimum_rotation.c \
	sort.c \
	push_swap.c

bonus_src = \
	operation_stack_bonus.c \
	checker_bonus.c \
	checker_util_bonus.c

obj = $(src:.c=.o)
mandatory_obj = $(mandatory_src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)

lib_dir = libft
lib_name = libft.a
lib_path = $(lib_dir)/$(lib_name)

NAME = push_swap
bonus_name = checker

all: $(lib_path) $(NAME)

bonus: $(lib_path) $(bonus_name)

$(lib_path):
	make -C $(lib_dir)

$(NAME): $(src) $(mandatory_src) $(obj) $(mandatory_obj) $(lib_path)
	$(CC) $(CFLAGS) $(src) $(mandatory_src) -o $(NAME) $(lib_path)

$(bonus_name): $(src) $(bonus_src) $(obj) $(bonus_obj) $(lib_path)
	$(CC) $(CFLAGS) $(src) $(bonus_src) -o $(bonus_name) $(lib_path)

clean:
	make clean -C $(lib_dir)
	rm -f $(obj) $(mandatory_obj) $(bonus_obj)

fclean: clean
	make fclean -C $(lib_dir)
	rm -f $(NAME) $(bonus_name)

re: fclean all

.PHONY: all clean fclean re libft bonus