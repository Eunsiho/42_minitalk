# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:55:55 by hogkim            #+#    #+#              #
#    Updated: 2022/05/04 22:22:28 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			= server
CLIENT			= client
PRINTF			= libftprintf.a

SERVER_SRC		= server.c
SERVER_OBJ		= server.o
CLIENT_SRC		= client.c
CLIENT_OBJ		= client.o

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror


.o : .c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(SERVER) $(CLIENT)

bonus : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT) : $(CLIENT_OBJ) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^

$(PRINTF) :
	make -C ft_printf
	cp ft_printf/libftprintf.a .

clean :
	rm -rf $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_B) $(CLIENT_OBJ_B)
	make -C ft_printf clean

fclean : clean
	rm -rf server client libftprintf.a
	make -C ft_printf fclean

re : fclean all
