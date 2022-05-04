# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:55:55 by hogkim            #+#    #+#              #
#    Updated: 2022/05/04 16:00:01 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		= server
CLIENT		= client
LIBFT		= libft.a

SERVER_SRC	= server.c
SERVER_OBJ	= server.o

CLIENT_SRC	= client.c
CLIENT_OBJ	= client.o

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT) : $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
	make -C libft
	cp libft/libft.a .

clean :
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C libft clean

fclean : clean
	rm -rf server client
	make -C libft fclean

re : fclean all
