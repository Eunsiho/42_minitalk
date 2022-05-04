# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:55:55 by hogkim            #+#    #+#              #
#    Updated: 2022/05/04 13:39:04 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= server.c client.c
OBJS	 = $(SRCS:.c=.o)

CC		 = gcc
CFLAGS	 = -Wall -Wextra -Werror -g

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) libft/libft.a server.o -o server
	$(CC) $(CFLAGS) libft/libft.a client.o -o client

clean :
	rm -rf $(OBJS)
	make -C libft clean

fclean : clean
	rm -rf server client
	make -C libft fclean

re : fclean all