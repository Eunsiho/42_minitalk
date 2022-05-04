# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:55:55 by hogkim            #+#    #+#              #
#    Updated: 2022/05/04 09:50:40 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= server.c client.c
OBJS	 = $(SRCS:.c=.o)

CC		 = gcc
CFLAGS	 = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $<

all : server client

server : server.o libft
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft

client : client.o libft
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft

libft : 
	make -C libft

clean :
	rm -rf $(OBJS)
	make -C libft clean

fclean : clean
	rm -rf server client
	make -C libft fclean

re : fclean all