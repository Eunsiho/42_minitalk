# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:55:55 by hogkim            #+#    #+#              #
#    Updated: 2022/05/03 15:06:22 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= server.c client.c
OBJS	 = $(SRCS:.c=.o)

CC		 = gcc
CFLAGS	 = -Wall -Wextra -Werror

all :
	make all -C ft_printf
	$(CC) $(CFLAGS) server.c ft_printf/libftprintf.a -o server
	$(CC) $(CFLAGS) client.c ft_printf/libftprintf.a -o client

clean :
	make clean -C ft_printf
	rm -rf server
	rm -rf client

fclean : clean
	
