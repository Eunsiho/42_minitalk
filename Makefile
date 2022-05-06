# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:55:55 by hogkim            #+#    #+#              #
#    Updated: 2022/05/06 13:11:14 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk
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

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

bonus : $(NAME)

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

re :
	make fclean
	make all
