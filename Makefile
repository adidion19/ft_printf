# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adidion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 11:17:06 by adidion           #+#    #+#              #
#    Updated: 2021/01/26 11:20:52 by adidion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS =	ft_printf.c

OBJS = $(SRCS:.c=.o)

LINK = ar rc

all : $(NAME)

$(NAME):	$(OBJS)
	$(LINK) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OB)

fclean: clean
	rm -f $(NAME) $(OB)

re: fclean all

.PHONY: re bonus clean fclean all
