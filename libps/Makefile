# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 22:54:08 by ccodere           #+#    #+#              #
#    Updated: 2024/09/17 17:38:16 by ccodere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libps.a

HEADER = push_swap.h

SRCS = ft_lastnode.c ft_newnode.c ft_addnode_back.c ft_perror.c utils.c \
	   push.c reverse_rotate.c rotate.c swap.c ft_free.c ft_args_checker.c \
	   ft_tab_checker.c ft_algorithms.c ft_radix_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
