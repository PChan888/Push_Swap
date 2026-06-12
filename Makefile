# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2026/06/11 00:00:00 by kai               #+#    #+#             #
#   Updated: 2026/06/11 00:00:00 by kai              ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
	error_exit.c \
	list_utils.c \
	parser_input.c \
	parser_utils.c \
	op_push.c \
	op_swap.c \
	op_rotate.c \
	op_rev_rotate.c \
	sort_algorithms.c \
	sort_utils.c \
	large_sort.c \
	turk_utils.c \
	turk_b_utils.c \
	turk_exec.c

OBJS = $(SRCS:.c=.o)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
