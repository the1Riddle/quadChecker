# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falupine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 10:20:56 by falupine          #+#    #+#              #
#    Updated: 2018/08/19 22:10:07 by falupine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=colle-2
CC=gcc -Wall -Wextra -Werror
SRCS=./srcs/main.c			\
	 ./srcs/rush02.c		\
	 ./srcs/ft_putchar.c	\
	 ./srcs/ft_putstr.c		\
	 ./srcs/ft_putnbr.c		\
	 ./srcs/check.c			\
	 ./srcs/alter_check.c	\
	 ./srcs/ft_strlen.c		\
	 ./srcs/reader.c
HEADERS=./includes

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRCS) -I $(HEADERS)

fclean:
	rm -rf $(NAME)

clean: fclean

re: fclean all
