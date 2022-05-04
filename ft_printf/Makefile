# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 15:13:59 by hogkim            #+#    #+#              #
#    Updated: 2022/05/03 14:54:41 by hogkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ft_parsing_utils.c \
			  ft_print_c.c ft_print_di.c \
			  ft_print_di2.c ft_print_p.c \
			  ft_print_per.c ft_print_s.c \
			  ft_print_u.c ft_print_x.c \
			  ft_printf.c ft_utils1.c \
			  ft_utils2.c ft_utils3.c
OBJS		= $(SRCS:.c=.o)

AR			= ar
ARFLAGS		= rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(ARFLAGS) $@ $?

all : $(NAME)

bonus : $(NAME)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

clean :
	rm -rf $(OBJS)
	make clean -C $(LIBFT)

re : fclean all
