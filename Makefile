# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 12:35:07 by ccodere           #+#    #+#              #
#    Updated: 2024/09/20 01:57:30 by ccodere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

LIBPS_DIR = libps

LIBPS = $(LIBPS_DIR)/libps.a

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(LIBPS) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(LIBPS):
	$(MAKE) -C $(LIBPS_DIR) all
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBPS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBPS_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBPS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
